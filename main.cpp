#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

using namespace std;


int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::AddressBook addressBook;
    int i;

    for(i=0;i<1000000;i++){
        tutorial::Person* person = addressBook.add_person();
        string name("test"+std::to_string(i));
        string mail(name+"@test.com");
        person->set_name(name);
        person->set_email(mail);
        person->set_id(i);
    }


    string fileName("save_file.txt");

    fstream output(fileName, ios::out | ios::trunc | ios::binary);
    if (!addressBook.SerializeToOstream(&output)) {
        cerr << "Failed to write address book." << endl;
        return -1;
    }

    fstream input(fileName, ios::in | ios::binary);
    tutorial::AddressBook addressBook2;
    addressBook2.ParseFromIstream(&input);
    for(i=0;i<addressBook2.person_size();i++ )
    {
        tutorial::Person person = addressBook2.person(i);
        cout << person.id() << " " << person.name() << " " << person.email() << endl;


    }


    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
