#include "face_detect.h"

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpClient.h>

#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include <fstream>

#include <stdio.h>

using namespace muduo;
using namespace muduo::net;

#define PACK_SIZE 1024


bool verify(const muduo::string& result)
{
  return true;
}

class FaceClient : boost::noncopyable
{
 public:
  FaceClient(EventLoop* loop,
                const InetAddress& serverAddr,
               const muduo::string& name
               )
    : name_(name),
      client_(loop, serverAddr, name_)
  {
    client_.setConnectionCallback(
        boost::bind(&FaceClient::onConnection, this, _1));
    client_.setMessageCallback(
        boost::bind(&FaceClient::onMessage, this, _1, _2, _3));
  }

  void connect()
  {
    client_.connect();
  }

 private:
  void onConnection(const TcpConnectionPtr& conn)
  {
    if (conn->connected())
    {
      LOG_INFO << name_ << " connected";
      start_ = Timestamp::now();
      std::string temp=process("/home/llw/Project/wcdCFacerecognize/registerimg/15.bmp");
      conn->send(temp);
      temp=process("/home/llw/Project/wcdCFacerecognize/registerimg/13.bmp");
      conn->send(temp);
      temp=process("/home/llw/Project/wcdCFacerecognize/registerimg/3.bmp");
      conn->send(temp);
      temp=process("/home/llw/Project/wcdCFacerecognize/registerimg/18.bmp");
      conn->send(temp);
      temp=process("/home/llw/Project/wcdCFacerecognize/registerimg/31.bmp");
      conn->send(temp);
      //conn->send(temp);

      //while(temp.size()>PACK_SIZE)
      //{
      //    std::string send_tmp=temp.substr(0,PACK_SIZE);
      //    conn->send(send_tmp);
      //    temp=temp.substr(PACK_SIZE);
      //}
      //if(temp.size()>0)
      //  conn->send(temp);
      LOG_INFO << name_ << " sent requests";
    }
    else
    {
      LOG_INFO << name_ << " disconnected";
    }
  }

  void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp)
  {
    //LOG_DEBUG << buf->retrieveAllAsmuduo::string();

    size_t len = buf->readableBytes();
    cout<<"get face:"<<len<<endl;
    if(len==0)
        cout<<"No face!"<<endl;
    while (len)
    {
        std::string temp(buf->peek(), len);
        cout<<temp<<endl;
        buf->retrieveAll();
        len=buf->readableBytes();

    }


  }

  muduo::string name_;
  TcpClient client_;
  Timestamp start_;
};


int main(int argc, char* argv[])
{
    LOG_INFO << "pid = " << getpid() << ", tid = " << CurrentThread::tid();
    EventLoop loop;

    //mat=imread("/home/llw/Project/wcdCFacerecognize/registerimg/15.bmp");

    InetAddress seraddr("127.0.0.1",9981);
    FaceClient client(&loop,seraddr,"FaceClient");

    client.connect();
    loop.loop();
}
