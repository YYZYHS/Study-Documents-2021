#include "logindialog.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#pragma execution_character_set("utf-8")

LoginDialog::LoginDialog(QWidget *parent) :QDialog(parent)
{
    usrLabel = new QLabel(this);
	usrLabel->move(70, 80);
	usrLabel->setText("�û�����");
	usrLineEdit = new QLineEdit(this);
	usrLineEdit->move(140, 80);
	usrLineEdit->setPlaceholderText("�������û���:");

	pwdLabel = new QLabel(this);
	pwdLabel->move(70, 130);
	pwdLabel->setText("����:");
	pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140, 130);
	pwdLineEdit->setPlaceholderText("����������:");

	loginBtn = new QPushButton(this);
	loginBtn->move(50, 200);
	loginBtn->setText("��¼");
	editBtn = new QPushButton(this);
	editBtn->move(210, 200);
	editBtn->setText("�˳�");

	connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(login()));
	connect(editBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::login()
{
	if (usrLineEdit->text().trimmed()=="yonghuming"&&pwdLineEdit->text().trimmed()=="mima")
	{
		accept();
	}
	else
	{
		QMessageBox::warning(this, "���棡", "�û������������", QMessageBox::Yes);
		usrLineEdit->clear();
		pwdLineEdit->clear();
		usrLineEdit->setFocus();
	}
}
