#include <string>
#include <array>
using namespace std;

// Óskiljanlegt nafn, en þetta er concat með bili á milli
string cws(string s1, string s2) {
    return s1 + " " + s2;
}

// strings
const string Q = "Quit",
             S = "Send",
             B = "Back",
             MM = "Main menu",
             selText = "Enter id of email to select: ",
             bodyText = "Write text, then press CTRL+D when done",
             sendRecv = "Sending / Recieving mail please wait...",
             setInboxText = "Please enter number of emails per page: ";

// arrays
//const string loginMenu {"Set up new email", "Use previous email", Q}; 
string loginMenu[3] = {"Set up new email", "Use previous email", Q}; 
string mainMenu[5] = {"Inbox", "Send Email", S+"/Recieve", "Settings", Q};
string inboxCmd[4] = {"Select/Read (s)", "Next page (->)", "Previous page (<-)", MM+" (q)"};
string selCmd[2] = {"Delete (x)", B+" (q)"};
string sendMenu[5] = {"Recipient", "Subject", "Body", S, MM};
string bodyMenu[3] = {"Use this", "Start again", S};
string sendSendMenu[2] = {S, B};
string settingsMenu[2] = {"Inbox page count", B};

