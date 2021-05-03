#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct node
{
char name[100];
struct node * left;
struct node *  right;

};
typedef struct node * NODE;
NODE searchNode(NODE temp, char name[100]) {
    //Check whether tree is empty
    if(temp == NULL){
        return NULL;
     }
     if(strcmp(temp->name,name)==0){
             return temp;
     }
    else {
        //If value is found in the given binary tree then, set the flag to true
        //Search in left subtree
        NODE found = searchNode(temp->left, name);
        //Search in right subtree
        if (found == NULL) {
            found = searchNode(temp->right,name );
        }
        return found;
    }
  }

NODE create(char name[100])
{
    NODE temp;

    temp=(NODE)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

NODE  add(NODE root,char friendName[100],char userName[100])
         {
              if (root == NULL){
            root = create(friendName);

         }
             NODE req=searchNode(root,friendName);
//if no user is existing

        if(req->left!=NULL&&req->right!=NULL){
                //Improvement to be done here
            printf("\n ur requested friend already has maximum number of freinds");
         }
            else if(req->left!=NULL){
                NODE temp = create(userName);
                req->right=temp;
            }
            else {
                NODE temp = create(userName);
                req->left=temp;
            }
            return root;
}

int flag=0;


void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("\n%s",root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

int count=0;



struct account
{
    char name[100];
    char username[100];
    char password[100];
    struct message{
char mes[300];
char sentby[100];
}m[10];

    int i;
};



int main()
{



    NODE root=NULL;
    struct account s[200];
start:system("cls");
printf("\t\t\t\t\t\t\tWELCOME TO FACEBOOK");
printf("\n1.LOGIN");
printf("\n2.SIGNUP");

int n;
 printf("\n");
scanf("%d",&n);
if(n==2)
{


    printf("\nPlease enter your name");
    printf("\n");
    scanf("\n%s",s[count].name);
    printf("\nPlease enter your username");
     printf("\n");
    scanf("\n%s",s[count].username);
    printf("\nPlease enter the password");
     printf("\n");
    scanf("\n%s",s[count].password);

    count+=1;
    printf("\nHurray ,you have succesfully signed up.");
    printf("\nPress 1 to go back to home page or press 0 to exit");
    int nn;
     printf("\n");
    scanf("\n%d",&nn);
    if(nn==1)
        goto start;
    else
        exit(0);
}
if(n==1)
{
    printf("\nenter your username:");
     printf("\n");
    char user[100];
    scanf("\n%s",user);
    int j,res;

    for(j=0;j<=count;j++)
        {
            if(strcmp(s[j].username,user)==0)
            {res=j;
            break;
            }
        }
        printf("\nenter your password");
         printf("\n");
        char pass[100];
        scanf("\n%s",pass);
        if(strcmp(s[res].password,pass)!=0)
           {

            printf("\n Sorry ,wrong password");
            printf("\n\nPress 1 to go back to home page or press 0 to exit");
             printf("\n");
    int ll;
    scanf("\n%d",&ll);
    if(ll==1)
        goto start;
    else
        exit(0);
}

       S: system("cls");
           printf("\n\t\t\t\t\tWELCOME BACK  %s ",s[res].name);
        printf("\n1.Add friends");
        printf("\n2.See people who have added you as their frend");
        printf("\n3.Send a message to your frend");
        printf("\n4.View all your messages");
        printf("\n5Logout");
        printf("\n6Exit");
         printf("\n");
        int nnn;
        scanf("%d",&nnn);
        if(nnn==1)
        {
            printf("\nenter the name of the friend  you want to add \n" );
             printf("\n");
        char fn[100];
        scanf("\n%s",fn);

        root=add(root,fn,s[res].name);
        printf("Hurray U have added %s as your friend",fn);


        printf("\n\n enter  1 to GO back");
         printf("\n");
            int x;
            scanf("\n%d",&x);
            goto S;

        }
        if(nnn==2)
        {
            if(root==NULL||(root->left==NULL&&root->right==NULL))
           {

            printf("\n You havent added anyone as your frend");

           }

                NODE req=searchNode(root,s[res].name);
                printf("\n People who added you as their freind and your mutual freinds are\n");
                preorder(req);



                printf("\n\n enter  1 to GO back");
            int z;
             printf("\n");
            scanf("\n%d",&z);
           goto S;

        }
       if(nnn==3)
        {

            printf("\n enter the name of the friend whm you want to send a message to");
            char f[100];
             printf("\n");
            scanf("\n%s",f);
            int k,result=0;
            for(k=0;k<=count;k++)
            {
                if(strcmp(s[k].name,f)==0)
                   {

                    result=k;
                    break;
                   }
            }
                   if(result==0)
                   {

                    printf("\n User u wish to send a message has not signed up on facebook");
                    printf("\n\n enter  1 to GO back");
            int f;
             printf("\n");
            scanf("\n%d",&f);
            goto S;

            }
            printf("\nenter the message you want to send");
            int cnt=s[result].i;
             printf("\n");

            scanf("\n%[^\n]s",s[result].m[cnt].mes);

            strcpy(s[result].m[cnt].sentby,s[res].name);

                        (s[result].i)+=1;
            printf("\n Your message has been sent!!!!");



            printf("\n\n enter  1 to GO back");
            int e;
             printf("\n");
            scanf("\n%d",&e);
            goto S;

        }
        if(nnn==4)
        {
            printf("\n Your messages are here\n");
            int c=s[res].i;
            int g;
            for (g=0;g<c;g++)

{

//if(strcmp(s[res].m[g].mes,NULL)!=0)
               {printf("%s",s[res].m[g].mes);
               printf(" \n");
               printf("Sent by: %s",s[res].m[g].sentby);
               printf("\n-------------------");
               printf(" \n");
               printf("\n");
               }
}


            printf("\n\n enter  1 to GO back");
            int d;
             printf("\n");
            scanf("\n%d",&d);
            goto S;


        }
        if(nnn==5)
            goto start;
        if(nnn==6)
            exit(0);
            else
                exit(0);





            }
        }
