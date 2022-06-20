#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Ambulance{              //Defining the Ambulance service
    char id[10];
    int location;
};

struct Security{
    char id[10];
    int location;
};

struct Food{
    char id[10];
    int location;
};

typedef struct node{            //Defining the node for linked list of all services
    struct Ambulance _Ambulance;
    struct Security _Security;
    struct Food _Food;
    struct node* link;
}node;

struct Ambulance* Ambulance_array;          //INitializing database for Ambulance
struct Security* Security_array;
struct Food* Food_array;

void create_database(){
    Ambulance_array=(struct Ambulance*)malloc(10*sizeof(struct Ambulance));
    Security_array=(struct Security*)malloc(10*sizeof(struct Security));
    Food_array=(struct Food*)malloc(10*sizeof(struct Food));

    //For Ambulance: id->
    strcpy(Ambulance_array[0].id,"AB1001");
    strcpy(Ambulance_array[1].id,"AB1002");
    strcpy(Ambulance_array[2].id,"AB1003");
    strcpy(Ambulance_array[3].id,"AB1004");
    strcpy(Ambulance_array[4].id,"AB1005");
    strcpy(Ambulance_array[5].id,"AB1006");
    strcpy(Ambulance_array[6].id,"AB1008");
    strcpy(Ambulance_array[7].id,"AB1009");
    //For Ambulance: location:->
    Ambulance_array[0].location=12;
    Ambulance_array[1].location=30;
    Ambulance_array[2].location=67;
    Ambulance_array[3].location=98;
    Ambulance_array[4].location=23;
    Ambulance_array[5].location=89;
    Ambulance_array[6].location=90;
    Ambulance_array[7].location=88;

    //For Security: id->
    strcpy(Security_array[0].id,"SC1001");
    strcpy(Security_array[1].id,"SC1002");
    strcpy(Security_array[2].id,"SC1003");
    strcpy(Security_array[3].id,"SC1004");
    strcpy(Security_array[4].id,"SC1005");
    strcpy(Security_array[5].id,"SC1006");
    strcpy(Security_array[6].id,"SC1008");
    strcpy(Security_array[7].id,"SC1009");

    //For Security location: ->
    Security_array[0].location=12;
    Security_array[1].location=30;
    Security_array[2].location=67;
    Security_array[3].location=98;
    Security_array[4].location=23;
    Security_array[5].location=89;
    Security_array[6].location=8;
    Security_array[7].location=88;

    //For Food id_>
    strcpy(Food_array[0].id,"FD1001");
    strcpy(Food_array[1].id,"FD1002");
    strcpy(Food_array[2].id,"FD1003");
    strcpy(Food_array[3].id,"FD1004");
    strcpy(Food_array[4].id,"FD1005");
    strcpy(Food_array[5].id,"FD1006");
    strcpy(Food_array[6].id,"FD1008");
    strcpy(Food_array[7].id,"FD1009");

    //For Food Location: 
    Food_array[0].location=12;
    Food_array[1].location=30;
    Food_array[2].location=67;
    Food_array[3].location=98;
    Food_array[4].location=23;
    Food_array[5].location=89;
    Food_array[6].location=80;
    Food_array[7].location=88;
}

node* create_linked_list(int num){
    create_database();
    node *head,*ptr;
    for(int i=0;i<num;i++){
        if(i==0){
            head=(node*)malloc(sizeof(node));
            ptr=head;
        }
        else{
            ptr->link=(node*)malloc(sizeof(node));
            ptr=ptr->link;
        }
        strcpy(ptr->_Ambulance.id,Ambulance_array[i].id);
        ptr->_Ambulance.location=Ambulance_array[i].location;

        strcpy(ptr->_Security.id,Security_array[i].id);
        ptr->_Security.location=Security_array[i].location;

        strcpy(ptr->_Food.id,Food_array[i].id);
        ptr->_Food.location=Food_array[i].location;
    }
    ptr->link=NULL;
    return head;
}

void display(node* head){
    node* ptr=head;
    int i=1;
    while(ptr!=NULL){
        printf("For the %d node the data is:\n",i);
        printf("\tAmbulance avialble id > %s\n",ptr->_Ambulance.id);
        printf("\tSecurity avialble id > %s\n",ptr->_Security.id);
        printf("\tFood avialble id > %s\n",ptr->_Food.id);
        i++;
        ptr=ptr->link;
    }
}

node* search_nearest_Services(node* head,int location,int x){
    if(x==1){
        node* ptr=head;
        int distance=abs(head->_Ambulance.location-location);
        node* result=head;
        while(ptr!=NULL){
            if(abs((ptr->_Ambulance.location)-location)<distance){
                distance=abs((ptr->_Ambulance.location)-location);
                result=ptr;
            }
            ptr=ptr->link;
        }
        return result;
    }
    else if(x==2){
        node* ptr=head;
        int distance=abs(head->_Security.location-location);
        node* result=head;
        while(ptr!=NULL){
            if(abs((ptr->_Security.location)-location)<distance){
                distance=abs((ptr->_Security.location)-location);
                result=ptr;
            }
            ptr=ptr->link;
        }
        return result;
    }
    else if(x==3){
        node* ptr=head;
        int distance=abs(head->_Food.location-location);
        node* result=head;
        while(ptr!=NULL){
            if(abs((ptr->_Food.location)-location)<distance){
                distance=abs((ptr->_Food.location)-location);
                result=ptr;
            }
            ptr=ptr->link;
        }
        return result;
    }
}

void Ambulance(){
    int location;
    printf("Enter your Location: ");
    scanf("%d",&location);
    node* head=create_linked_list(7);
    node* result=search_nearest_Services(head,location,1);
    printf("\nThe id of nearest Ambulance is: %s\n",result->_Ambulance.id);
}

void Security(){
    int location;
    printf("Enter your Location: ");
    scanf("%d",&location);
    node* head=create_linked_list(7);
    node* result=search_nearest_Services(head,location,2);
    printf("\nThe id of nearest Security is: %s\n",result->_Security.id);
}

void Food(){
    int location;
    printf("Enter your Location: ");
    scanf("%d",&location);
    node* head=create_linked_list(7);
    node* result=search_nearest_Services(head,location,3);
    printf("\nThe id of nearest Food is: %s\n",result->_Food.id);
}

void Support(){
    printf("Thanku so much for supporting us::\nYou have our heart----\n");
}

void Leave(){
    printf("Thanku so much for using our services!!\nWish you a very Happy life!!");
    exit(0);
}
 
int main(){
    //For the Admin:

    //
    int choice;
    printf("Enter the service you want: \n");
    printf("\tEnter 1 for Ambulance services>\n");
    printf("\tEnter 2 for Security services>\n");
    printf("\tEnter 3 for Food services>\n ");
    printf("\tEnter 4 to support us>\n");
    printf("\tEnter 5 to exit>\n");
    while(1){
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            Ambulance();
            break;
        case 2:
            Security();
            break;
        case 3:
            Food();
            break;
        case 4:
            Support();
            break;
        case 5:
            Leave();
            break;
        default:
            printf("Plz Enter a valid choice:");
            break;
        }
    }
    return 0;
}