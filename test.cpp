/*
Output:
socket error.

ToDo:
Fix ¯\_(ツ)_/¯
*/
#include <iostream>
#include <string>
#include "vmime/vmime.hpp"
#include "vmime/platforms/posix/posixHandler.hpp"
//Hello Örn, I am very sorry i did not use "using namespace std;" i owe you coffee.
//Authenticatin class(not implemented yet)
class myAuthenticator : public vmime::security::defaultAuthenticator{
	const std::string getUsername() const{
		std::cout << "Enter your username: " << std::endl;
		vmime::string res;
		std::getline(std::cin, res);
		return res;
	}
	const std::string getPassword() const{
		std::cout << "Enter your password: " << std::endl;
		vmime::string res;
		std::getline(std::cin,res);
		return res;
	}
};

//Basic message builder
void BuildEmail(){
	try
	{
		vmime::messageBuilder mb;
		mb.setSubject(vmime::text("Subject"));
		mb.setExpeditor(vmime::mailbox("To@example.com"));
		mb.getRecipients().appendAddress(vmime::make_shared <vmime::mailbox>("From@Example.com"));
		mb.getTextPart()->setCharset(vmime::charsets::ISO8859_15);
		mb.getTextPart()->setText(vmime::make_shared <vmime::stringContentHandler>("This is a message body..."));
		vmime::shared_ptr <vmime::message> msg = mb.construct();
		vmime::utility::outputStreamAdapter out(std::cout);
		msg->generate(out);
	}
	catch (vmime::exception& e)
	{
		std::cerr << "std::exception: " << e.what() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "std::exception: " << e.what() << std::endl;
	}
}

int main(){
	vmime::platform::setHandler<vmime::platforms::posix::posixHandler>();
	//gmail demo
	myAuthenticator usr;
	std::string str1 = "smtp:/";
	std::string str2 = "/smtp.gmail.com:465";
	std::string Gmail = str1 + str2;//I aM a GeNiUs
	const vmime::string msgData =
	"From: me@example.com \r \n"
	"To: you@example.com \r \n"
	"Date: Mon, Des 10 2018 16:25:29 +0200 \r \n"
	"Subject: test \r \n"
	"\r \n"
	"Message body";//Msg data
	vmime::utility::url url(Gmail);
	//create session
	vmime::shared_ptr <vmime::net::session> sess = vmime::net::session::create();
	std::cout << "session created" << std::endl;
	//create transport service
	vmime::shared_ptr <vmime::net::transport> tr = sess->getTransport(url);
	std::cout << "transport url set: " << Gmail << std::endl;
	//connect it
	tr->setProperty("connection.tls",true);
	tr->setProperty("options.need-authentication",true);
	tr->setProperty("auth.username","From@example.com");
	tr->setProperty("auth.password", "password");
	tr->setProperty("auth.accesstoken","yourAccessToken ");
	tr->connect();
	std::cout << "connected" << std::endl;
	//sent it
	vmime::utility::inputStreamStringAdapter is(msgData);
	vmime::mailbox from("From@example.com");
	vmime::mailboxList to;
	to.appendMailbox(vmime::make_shared <vmime::mailbox>("To@example.com"));
	tr->send(from,to,is,msgData.length());
	std::cout << "email sent" << std::endl;
	//disconnect it
	tr->disconnect();
	std::cout << "disconnected" << std::endl;
	return 0;

}
