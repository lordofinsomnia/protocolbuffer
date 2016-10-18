#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

using namespace std;


int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::AddressBook addressBook;

    string fileName("save_file.txt");

    fstream output(fileName, ios::out | ios::trunc | ios::binary);
    if (!addressBook.SerializeToOstream(&output)) {
        cerr << "Failed to write address book." << endl;
        return -1;
    }


    cout << "Hello World!" << endl;
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
