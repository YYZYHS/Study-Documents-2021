#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("TCP Server"));
    ContentListWidget = new QListWidget;
    PortLabel = new QLabel(tr("端口："));
    PortLineEdit = new QLineEdit;
    CreateBtn = new QPushButton(tr("创建聊天室"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);

    port=8010;
    PortLineEdit->setText(QString::number(port));
    connect(CreateBtn,SIGNAL(clicked()),this,SLOT(slotCreateServer()));
}

TcpServer::~TcpServer()
{

}
void TcpServer::updateServer(QString msg,int length)
{
    ContentListWidget->addItem(msg.left(length));
}
void TcpServer::slotCreateServer()
{
    //创建一个Server对象
    server = new Server(this,port);
    //将Server类中的信号和TcpServer中的槽函数连接起来
    connect(server,SIGNAL(updateServer(QString,int)),this,
    SLOT(updateServer(QString,int))); //(a)
    //将信息显示到控件上
    CreateBtn->setEnabled(false);
}
