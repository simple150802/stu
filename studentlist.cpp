#include<iostream>

using namespace std;
template<class T>

#define MAX 100
#define max_of_course 5
struct Nodestu{
    T val;
    Nodestu* next;
};
struct course {
    string name;
    string code;
    double score;
    void print_course(){
    cout<<"Name: "<< name<<endl;
    cout<<"Code: "<< code<<endl;
    cout<<"Score: "<< score<<endl;
    }
};
typedef struct course* course_list;

struct student {
    string name;
    string dateofbirth;
    course clist[max_of_course];
    void print_student(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date of Birth: "<<dateofbirth<<endl;
        for(int i=0;i<max_of_course;i++){
            cout<<"Course :"<<i+1<<endl;
            clist[i].print_course();
        }
    };
};

typedef Nodestu<student>* stu_list;

void init(stu_list &head) {
    head == NULL;
}
int isEmpty(stu_list head)
{
    if(head != NULL) return 0;
    else return 1; // head == NULL
}
// insert student at the beginning of list
void insert_at_beginning(stu_list &H, student A) {
    Nodestu<student>* stu = new Nodestu<student>;
    stu->val = A;
    if(H == NULL){
        stu->next=NULL;
        H = stu;
    }
    else{
        stu->next = H;
        H = stu;
    }
}
// insert student at the ending of list
void insert_at_tail(stu_list &H, student A) {
    Nodestu<student>* stu = new Nodestu<student>;
    stu->val = A;
    stu->next = NULL;
    if(H == NULL){
        stu->next=NULL;
        H = stu;
    }
    else {
        Nodestu<student>* temp = H;
        while(temp->next){
            temp=temp->next;
        }
        temp->next = stu;
    }
}
// Counting student in the list 
int counting(stu_list H) {
    int count = 0;
    Nodestu<student>* tmp = H;
    while(tmp != NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}
///Print list of students
void printlist(stu_list H){
    Nodestu<student>*temp = H;
    while(temp){
        (temp->val).print_student();
        temp=temp->next;
    }
}
//Search the student who has the highest average score
void Searchmax(stu_list H){
    double max=0;
    student max_student;
    Nodestu<student>*temp = H;
    while(temp){
        double sum = 0;
        for(int i=0;i<max_of_course;i++){
            sum += temp->val.clist[i].score;
        }
        if(sum/max_of_course > max){
            max=sum/max_of_course;
            max_student = temp->val;
        }
        temp=temp->next;
    }
    cout<<"Student has the highest avg score: "<<endl;
    max_student.print_student();
}
// Insert student according to the alphabetical order of their names
void insertAlphabetical(stu_list &H, student K){
    Nodestu<student>* stu =new Nodestu<student>;
    stu -> val = K;
    stu->next = NULL;
    if(H == NULL){
        stu->next=NULL;
        H = stu;
    }
    else{
        Nodestu<student>*temp = H;
        while(temp->next){
            if(temp->val.name.compare(temp->next->val.name)>0){
                stu->next=temp->next;
                temp->next=stu;
                break;
            }
            temp=temp->next;
        }
        if(temp->next==NULL){
            temp->next=stu;
            stu->next=NULL;
        }
    }
}
int main() {
    stu_list H;
    student A;
    init(H);
    insert_at_beginning(H, A);
}