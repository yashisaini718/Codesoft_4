#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Task{
    string description ;
    bool completed;
    Task (const string& desc): description(desc), completed(false) {}
};
class ToDoList {
    private :
        vector<Task> tasks;
    public :
        void addTask(const string & descript)
        {
            tasks.push_back(Task(descript));
            cout<<"Task added successfully\n";
        }

        void ViewTasks(){
            if(tasks.empty()){
                cout<<"No Task to display. \n";
                return;
            }
            cout<<"Tasks:\n";
            for(size_t i=0;i<tasks.size();++i){
                cout<<i+1<<".";
                if(tasks[i].completed){
                    cout<<"Completed ! ";
                }
                else{
                    cout<<"Pending ! ";
                }
                cout<<tasks[i].description<<endl;
            }
        }

        void MarkAsDone(size_t ind){
            if(ind>=1 && ind<=tasks.size()){
                tasks[ind-1].completed=true;
                cout<<"Task marked as completed .\n";
            }
            else{
                cout<<"Invalid task index .\n";
            }
        }

        void removeTask(size_t ind){
            if(ind>=1 && ind<=tasks.size()){
                tasks.erase(tasks.begin()+ (ind-1));
                cout<<"Task removed successfully.\n";
            }
            else{
                cout<<"Invalid task index .\n";
            }
        }
};

int main(){
    ToDoList list;
    int ch;
    string description;
    size_t index;
    cout<<"WELCOME TO THE TODO LIST MANAGER"<<endl;
    while(true){
        cout<<"\n\nChoose the operations from the list below:\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Task\n";
        cout<<"3. Mark Task as completed\n";
        cout<<"4. Remove Task\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice :";
        cin>>ch;
        if(ch==1){
            cout<<"Enter task description : ";
            cin.ignore();
            getline(cin,description);
            list.addTask(description);
        }
        else if(ch==2){
            list.ViewTasks();
        }
        else if(ch==3){
            cout<<"Enter the task index to mark completed :";
            cin>>index;
            list.MarkAsDone(index);
        }
        else if(ch==4){
            cout<<"Enter the task index to remove task :";
            cin>>index;
            list.removeTask(index);
        }
        else if (ch==5){
            return 0;
        }
        else{
            cout<<"Invalid Choice . \n";
        }
    }
    return 0;

}