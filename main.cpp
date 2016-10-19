#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "addressbook.pb.h"

using namespace std;


int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::AddressBook addressBook;
    int i;

    for(i=0;i<9000000;i++){
        tutorial::Person* person = addressBook.add_person();
        string name("test"+std::to_string(i));
        string mail(name+"@test.com");
        person->set_name(name);
        person->set_email(mail);
        person->set_id(i);
    }


    string fileName("save_file.txt");

    fstream output(fileName, ios::out | ios::trunc | ios::binary);
    auto start = std::chrono::steady_clock::now();
    if (!addressBook.SerializeToOstream(&output)) {
        cerr << "Failed to write address book." << endl;
        return -1;
    }
    auto duration = std::chrono::duration_cast< std::chrono::milliseconds >
                                (std::chrono::steady_clock::now() - start);
    cout << "save time" << duration.count() << endl;

    fstream input(fileName, ios::in | ios::binary);
    tutorial::AddressBook addressBook2;

    start = std::chrono::steady_clock::now();
    addressBook2.ParseFromIstream(&input);    
    /*for(i=0;i<addressBook2.person_size();i++ )
    {
        tutorial::Person person = addressBook2.person(i);
        cout << person.id() << " " << person.name() << " " << person.email() << endl;
    }*/

    duration = std::chrono::duration_cast< std::chrono::milliseconds >
                                (std::chrono::steady_clock::now() - start);
    cout << "load time" << duration.count() << endl;

    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
