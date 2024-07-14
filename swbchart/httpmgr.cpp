#include "httpmgr.h"

HttpMgr::~HttpMgr()
{

}

void HttpMgr::PostHttpReq(QUrl url, QJsonObject json, ReqId req_id, Modules mod)
{
    //创建一个HTTP POST请求，并设置请求头和请求体
      QByteArray data = QJsonDocument(json).toJson();
      //通过url构造请求
      QNetworkRequest request(url);
      request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
      request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));
      //发送请求，并处理响应, 获取自己的智能指针，构造伪闭包并增加智能指针引用计数
      auto self = shared_from_this();
      QNetworkReply * reply = _manager.post(request, data);

}

HttpMgr::HttpMgr()
{

}
