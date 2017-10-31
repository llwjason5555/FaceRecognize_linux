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

muduo::string request;
muduo::string left_str;

//int total_ace=0;
//int flag=1;
//long str_len=0;

class FaceServer
{
 public:
  FaceServer(EventLoop* loop, const InetAddress& listenAddr)
    : server_(loop, listenAddr, "FaceServer"),
      startTime_(Timestamp::now())
  {
    server_.setConnectionCallback(
        boost::bind(&FaceServer::onConnection, this, _1));
    server_.setMessageCallback(
        boost::bind(&FaceServer::onMessage, this, _1, _2, _3));
  }

  void start()
  {
    server_.start();
  }

 private:
  void onConnection(const TcpConnectionPtr& conn)
  {
    LOG_TRACE << conn->peerAddress().toIpPort() << " -> "
        << conn->localAddress().toIpPort() << " is "
        << (conn->connected() ? "UP" : "DOWN");
  }

  void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp)
  {
    LOG_DEBUG << conn->name();
    size_t len = buf->readableBytes();
    //total_ace+=len;
    cout<<"accept:"<<len<<endl;

    while (len)
    {
        muduo::string temp=buf->toStringPiece().as_string();
        //if(flag)
        //{
        //    muduo::string::iterator it=find(temp.begin(),temp.end(),':');
        //    muduo::string res_len;
        //    res_len.assign(temp.begin(),it);
        //    cout<<"toatl(string):"<<res_len<<"   size:"<<res_len.size()<<endl;
        //    str_len=stol(res_len);
        //    cout<<"total:"<<str_len<<endl;
        //    flag=0;
        //    muduo::string temp_str;
        //    temp_str.assign(it+1,temp.end());
        //    temp=temp_str;


        //}
        if(len>PACK_SIZE-request.size())
        {
            left_str=temp.substr(PACK_SIZE-request.size());
            temp=temp.substr(0,PACK_SIZE-request.size());

            //cout<<"temp size:"<<temp.size()<<endl;
            request+=temp;
            buf->retrieveAll();
            len = buf->readableBytes();
            break;
        }
        //cout<<"temp size:"<<temp.size()<<endl;
        request+=temp;
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
    if(request.size()==PACK_SIZE)
    {
        processRequest(conn, request);
        request=left_str;
        left_str.clear();

    }
    //cout<<total_ace<<endl;

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

      conn->send(result);

    }
    else
    {
      goodRequest = false;
    }
    return goodRequest;
  }

  TcpServer server_;
  Timestamp startTime_;
};

int main(int argc, char* argv[])
{
  LOG_INFO << "pid = " << getpid() << ", tid = " << CurrentThread::tid();
  EventLoop loop;
  InetAddress listenAddr(9981);
  FaceServer server(&loop, listenAddr);

  caffe_init();

  server.start();

  loop.loop();

}

