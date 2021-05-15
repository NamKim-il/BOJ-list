#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;
ifstream ifs("D://heapsort.in");
ofstream of("D://heapsort.out");
typedef struct heap{
    int data;
    struct heap *left;
    struct heap *right;
}*heaptr;
int size=0;
int height;
void inorder(heaptr root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        of<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(heaptr root)
{
    if(root!=NULL)
    {
        of<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int makebinary(int num)
{
    int ret=1;
    while(num>0)
    {
        ret=ret*2+num%2;
        num=num/2;
    }
    return ret/2;
}
heaptr newnode(int data)
{
    heaptr a=(heaptr)malloc(sizeof(struct heap));
    a->data=data;
    a->right=NULL;
    a->left=NULL;
    return a;
}
void swap(heaptr par, heaptr child)
{
    int tmp=par->data;
    par->data=child->data;
    child->data=tmp;
}
heaptr append(heaptr root,heaptr node,int siz)
{
    if(siz==1)
        return node;

    else{
        if(siz%2==0)
            root->left=append(root->left,node,siz/2);
        else if(siz%2==1)
            root->right=append(root->right,node,siz/2);
    }

    if(siz>0){
        if(siz%2==0 && (root->data > root->left->data) )
            swap(root,root->left);
        else if(siz%2==1 && (root->data > root->right->data))
            swap(root,root->right);
    }
    return root;
}

heaptr del(heaptr root)
{
    if(size==1)
    {
        of<<root->data;
        size--;
        free(root);
        return NULL;
    }
    int siz=makebinary(size);
    heaptr x=root,y;
    while(siz>1) {
        if(siz==2||siz==3)
        {
            y=x;
        }
        if(siz%2==0) x=x->left;
        else x=x->right;

        siz=siz/2;
    }
    of<<root->data<<" ";
    root->data=x->data;
    if(y->right!=NULL)
    {
        y->right=NULL;
    }
    else y->left=NULL;
    siz=--size;
    x=root;
    while(x->left!=NULL || x->right!=NULL)
    {
        if(x->right!=NULL && x->left!=NULL){
            if(x->right->data < x->data && x->left->data < x->data){
                if(x->right->data > x->left->data){
                    swap(x,x->left);
                    x=x->left;
                }
                else {
                    swap(x,x->right);
                    x=x->right;
                }
            }
            else if(x->right->data < x->data){
                swap(x,x->right);
                x=x->right;
            }
            else if(x->left->data < x->data){
                swap(x,x->left);
                x=x->left;
            }
            else break;

        }
        else {
            if(x->left->data < x->data){
                swap(x,x->left);
                x=x->left;
            }
            else break;
        }
    }
    return root;
}

int main()
{
    int n=0;
    string s;
    getline(ifs,s);
    for(int i=0;i<s.length();i++)
    {
        n=n*10+s[i]-'0';
    }
    of<<n<<endl;
    for(int count=0;count<n;count++)
    {
        heaptr root=NULL;
        string s;
        getline(ifs,s);
        int d,j=0,len=s.length();
        while(j<len)
        {
            d=0;
            while(s[j]>='0'&&s[j]<='9'){
                d=d*10+(s[j]-'0');
                j++;
            }

            size++;
            root=append(root,newnode(d),makebinary(size));
            j++;
        }
        of<<"I ";
        inorder(root);
        of<<endl<<"P ";
        preorder(root);
        of<<endl;
        while(root!=NULL)
        {
            root=del(root);
        }
        of<<endl;
    }
}

















