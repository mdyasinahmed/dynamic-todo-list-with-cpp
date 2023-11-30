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
    cout << endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<< endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
    cout << endl << endl;
    
    todo todo;

    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task);
    ID++; 

    //write task to todo.txt
    ofstream write;
    write.open("todo.txt", ios::app);
    write << endl << ID;
    write << endl << todo.task ;
    write.close();

    //write the id to a new file
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"\t\t\tDo you want to add more task? y/n: ";
    cin>> ch;

    //if wants to add a new task again
    if(ch == 'y') {
        addToDo();
    }
    else {
        cout << "\n\t\t\tTask has been added successfully";
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
    cout << endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<< endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
    cout << endl << endl;
    
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
    cout << endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<< endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
    cout << endl << endl;
    
    int id;
    cout << "\n\t\t\tEnter task id: ";
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
    cout << endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<< endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
    cout << endl << endl;
    
    int id = searchData();
    cout << "\n\t\t\tDo you want to delete this task (y/n) : ";
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
                tempFile << endl << todo.id;
                tempFile << endl << todo.task;
            }
        }
        read.close();
        tempFile.close();

        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\t\t\tTask deleted Successfully";
    } else {
        cout << "\n\t\t\tTask not deleted";
    }
}

// updateData function
void updateData() {
    system("cls");
    cout << endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<< endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
    cout << endl << endl;
    
    int id = searchData();
    cout << "\n\t\t\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;

    if(choice == 'y') {
        todo newData;
        cout << "\n\t\t\tEnter todo task : ";
        cin.get();
        getline(cin, newData.task);

        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while(!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if(todo.id != id) {
                tempFile << endl << todo.id;
                tempFile << endl << todo.task;
            } else {
                tempFile << endl << todo.id;
                tempFile << endl << newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\t\t\tTask updated successfully";
    } else {
        cout << "\n\t\t\tTask not deleted";
    }
}


// main function
int main() {
    system("cls");
	system("Color 1F");
    system("title YASIN's To-Do");
    cout << endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
	cout<<"\t\t\t                       WELCOME! List Your To-Do                       "<< endl;
    cout<<"\t\t\t-----------------------------------------------------------------------"<< endl;
    cout << endl << endl;

    ifstream read;
    read.open("id.txt");
    if(!read.fail()) {
        read >> ID;
    } else {
        ID = 0;
    }
    read.close();

    while(true) {
        cout<<endl<<endl;
        cout << "\n\t\t\t1. Add Tasks" << endl;
        cout << "\n\t\t\t2. See Tasks" << endl;
        cout << "\n\t\t\t3. Search Tasks" << endl;
        cout << "\n\t\t\t4. Delete Tasks" << endl;
        cout << "\n\t\t\t5. Update Tasks" << endl;

        int choice;
        cout << "\n\t\t\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addToDo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

    cout << endl << endl;
    return 0;
}