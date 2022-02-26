/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
//creating a node
struct node
{
   string fname , number,lname ;
   node *next;
};
node *head = NULL , *newnode , *temp;
int len = 0 ;
//taking input from user
void C_node ()
{
    newnode = new node;
    cout<<"Enter First Name: "<<endl;
    cin>>newnode->fname;
    cout<<"Enter Last Name: "<<endl;
    cin>>newnode->lname;
    cout<<endl;
    cout<<"Enter number: "<<endl;
    cin>>newnode->number;
    cout<<endl;
    int leng=newnode->number.length();
    if(leng<10){
        cout<<"You entered an invalid number!" <<endl;
        cout<<"Please check and enter again!"<<endl;
        C_node();
    }
    cout<<"Contact has been saved successfully."<<endl;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
//function to print the Contact information
void display ()
{
    //check if the list is empty
    if(head == NULL)
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)
        {
            cout<<"\n\t\tFull Name "<<trav->fname<<" "<<trav->lname<<endl;
            cout<<"\t\tPhone Number "<<trav->number<<endl;
            trav= trav->next;
            len++;
        }
        
        cout<<"Total contacts in the list = "<<len<<endl;
    }
}
void search_contact ()
{
    node *search_node = head;
    string key_contact; //the contact you want to search
    int count = 1;
    cout<<"Enter the first name of the contact you want to search: "<<endl;
    cin>>key_contact;
    bool found = false;
    if(head == NULL)
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if(key_contact == search_node->fname|| key_contact == search_node->number)
            {
                cout<<"\n\t\tFull name: "<<search_node->fname<<" "<<search_node->lname<<endl;
                cout<<"\t\tPhone number: "<<search_node->number<<endl;
                found =true;
                //break;
                if(found == true)
                {

                    cout<<"\t\tIndex of the Contact = "<<count<<endl;
                }
            }
            if (found == false){
                cout<<"Desired contact not found"<<endl;
            }
            search_node = search_node->next;
            count++;
        }
    }
    
}
//deletion function
void at_given () 
{
    int pos ;
    node *next_node;
    temp = head;
    cout<<"Enter your desired position from where you want to delete contact "<<endl;
    cin>>pos;
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    else
    {
        for (int i = 1 ; i<pos ; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact has been deleted "<<endl;
    }
}
void clear_all ()
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        temp = head ;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\n\t\tALL contact list has been deleted "<<endl;
    }
}
void menu ()
{
    cout<<"_____CHOOSE YOUR ACTIVITY____"<<endl;
    cout<<endl;
    cout<<"Press 1 to add contact in the phone book. "<<endl;
    cout<<endl;
    cout<<"Press 2 to display all contacts in the phone book.  "<<endl;
    cout<<endl;
    cout<<"Press 3 to search contact."<<endl;
    cout<<endl;
    cout<<"Press 4 to delete contact from where you want. "<<endl;
    cout<<endl;
    cout<<"Press 5 to clear All record. "<<endl;
    cout<<endl;
}
int main ()
{
    int op;
    while (true )
    {
        menu();
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            break;
        case 2:
            len = 0;
            display();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clear_all();
            break;
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}

