#include "facerecognize.h"

#include <muduo/base/Atomic.h>
#include <muduo/base/Logging.h>
#include <muduo/base/Thread.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>

#include <boost/bind.hpp>

#include <utility>

#include <stdio.h>
#include <unistd.h>
#include <algorithm>

using namespace muduo;
using namespace muduo::net;

const int PACK_SIZE = 474570;

typedef struct recv_data
{
    muduo::string request;
    muduo::string left_str;
} recv_data;

//int total_ace=0;
//int flag=1;
//long str_len=0;

class FaceServer
{
 public:
  FaceServer(EventLoop* loop, const InetAddress& listenAddr, int numThreads)
    : server_(loop, listenAddr, "FaceServer"),
      numThreads_(numThreads),
      startTime_(Timestamp::now())
  {
    server_.setConnectionCallback(
        boost::bind(&FaceServer::onConnection, this, _1));
    server_.setMessageCallback(
        boost::bind(&FaceServer::onMessage, this, _1, _2, _3));
    server_.setThreadNum(numThreads);
  }

  void start()
  {
    LOG_INFO << "starting " << numThreads_ << " threads.";
    server_.start();
  }

 private:
  void onConnection(const TcpConnectionPtr& conn)
  {
    LOG_TRACE << conn->peerAddress().toIpPort() << " -> "
        << conn->localAddress().toIpPort() << " is "
        << (conn->connected() ? "UP" : "DOWN");
    recv_data temp_data;
    conn->setContext(temp_data);
  }

  void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp)
  {
    LOG_DEBUG << conn->name();
    size_t len = buf->readableBytes();
    //total_ace+=len;
    cout<<"accept:"<<len<<endl;

    recv_data temp_data=boost::any_cast<recv_data>(conn->getContext());
    //vector<string> temp_data=boost::any_cast<vector<string>>(conn->getContext());
    while (len)
    {
        muduo::string temp=buf->toStringPiece().as_string();

        if(len>PACK_SIZE-temp_data.request.size())
        {

            temp_data.left_str=temp.substr(PACK_SIZE-temp_data.request.size());
            temp=temp.substr(0,PACK_SIZE-temp_data.request.size());

            //cout<<"temp size:"<<temp.size()<<endl;
            temp_data.request+=temp;
            //conn->setContext(temp_data);

            buf->retrieveAll();
            len = buf->readableBytes();
            break;
        }
        //cout<<"temp size:"<<temp.size()<<endl;

        temp_data.request+=temp;
        //conn->setContext(temp_data);
        //request+=temp;
        //buf->retrieveUntil(crlf + 2);
        buf->retrieveAll();
        len = buf->readableBytes();
        //if (!processRequest(conn, request))
        //{
        //  conn->send("Bad Request!\r\n");
        //  conn->shutdown();
        //  break;
        //}

      //else if (len > 100) // id + ":" + kCells + "\r\n"
      //{
      //  conn->send("Id too long!\r\n");
      //  conn->shutdown();
      //  break;
      //}

    }
    //cout<<"buff size:"<<len<<endl;
    //cout<<"left size:"<<left_str.size()<<endl;
    //cout<<"request size:"<<request.size()<<endl;
    if(temp_data.request.size()==PACK_SIZE)
    {
        processRequest(conn, temp_data.request);
        temp_data.request=temp_data.left_str;
        temp_data.left_str.clear();

    }
    //cout<<total_ace<<endl;
    conn->setContext(temp_data);

  }

  bool processRequest(const TcpConnectionPtr& conn, const muduo::string& request)
  {
    std::string id;
    muduo::string puzzle;
    bool goodRequest = true;

    muduo::string::const_iterator colon = find(request.begin(), request.end(), ':');
    if (colon != request.end())
    {
      id.assign(request.begin(), colon);
      puzzle.assign(colon+1, request.end());
    }
    else
    {
      puzzle = request;
    }

    if (puzzle.size()>0)
    {
      LOG_DEBUG << conn->name();
      std::string result = solveFacerec(request);

      conn->send(process_res(result));

    }
    else
    {
      goodRequest = false;
    }
    return goodRequest;
  }

  TcpServer server_;
  int numThreads_;
  Timestamp startTime_;
  //muduo::string request;
  //muduo::string left_str;
};

int main(int argc, char* argv[])
{
  LOG_INFO << "pid = " << getpid() << ", tid = " << CurrentThread::tid();
  int numThreads = 4;
  EventLoop loop;
  InetAddress listenAddr(9981);
  FaceServer server(&loop, listenAddr,numThreads);

  caffe_init();

  server.start();

  loop.loop();

}

