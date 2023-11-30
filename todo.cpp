// Bismillahir-Rahmanir-Raheem 
/*
    SHORT DESCRIPTION:
    Simple "To-Do" console application with C++
    Features:
        ~ Add Task
        ~ See Task Lists
        ~ Search Tasks
        ~ Delete Tasks
        ~ Update Tasks

    Project by: Md. Yasin Ahmed Mahi
                CSE, Metropolitan University, Sylhet, Bangladesh

*/

// all headers
#include <bits/stdc++.h>
using namespace std;

int ID;

// todo custom type
struct todo {
    int id;
    string task;
};

// addToDo function
void addToDo() {
    system("cls");
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl<<endl<<endl;
    
    todo todo;

    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task);
    ID++; 

    //write task to todo.txt
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    //write the id to a new file
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"Do you want to add more task? y/n"<<endl;
    cin>> ch;

    //if wants to add a new task again
    if(ch == 'y') {
        addToDo();
    }
    else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}

// printToDo function
void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

// readData function
void readData() {
    system("cls");
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl<<endl<<endl;
    
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t------------------Your current Tasks in the list--------------------";
    
    while(!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}
// searchData function
int searchData() {
    system("cls");
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl<<endl<<endl;
    
    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;
    cout << "\n\n\n";

    todo todo;
    ifstream read;
    read.open("todo.txt");

    while(!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}
// deleteData function
void deleteData() {
    system("cls");
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<<endl<<endl<<endl;
    
    int id = searchData();
    cout << "\n\tDo you want to delete this task (y/n) : ";
    char choice;
    cin >> choice;

    if(choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();

        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted Successfully";
    } else {
        cout << "\n\tRecord not deleted";
    }
}

// updateData function



// main function
int main() {
    


    return 0;
}