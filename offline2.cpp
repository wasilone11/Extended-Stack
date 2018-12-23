
#include<iostream>
#define SIZE 10
using namespace std;
class stack
{
    int size=10;
    int previousSize;
    int arr[SIZE];
    int top;
    int index;
    int y;
    int *ptr;
    int *var;
public:
    stack()
    {
        top=0;
        ptr=new int[size];
        var=new int[size];
    }
    ~stack()
    {
        delete[] ptr;
        cout<<"F R E E D !"<<endl;
    }
    void push(int a)
    {
        if(top==size)
        {
            Resize();
        }
        index=a;
        ptr[top]=a;
        top++;
    }
    void push(int *ara)
    {
        int i, previousSize;
        previousSize=y;
        for(i=0; i<previousSize; i++,top++)
        {
            *(ptr+top)=ara[i];
            index=*(ptr+top);
            //top++;
            if(top==size)
                Resize();
        }
    }
    void push(stack s )
    {
        int j, z=s.top;
        for(j=0; j<z; j++,top++)
        {
            *(ptr+top)=s.pop();
            index=*(ptr+top);
            //top++;
            if(top==size)
                Resize();
        }
    }
    int pop()
    {
        if(top==0)
        {
            cout<<"Stack is empty "<<endl;
        }
        else
            Shrink();
        top--;
        index=*(ptr+(top-1));
        return  *(ptr+top);
        //return arr[--top];
    }
    int Top()
    {
        return index;
    }
    int Size()
    {
        return top;
    }

    void Resize()  //increases the size
    {
        int k;
        previousSize=size;
        var=new int[size];
        for(k=0; k<size; k++)
        {
            var[k]=ptr[k];
        }
        size=size+10;
        ptr=new int[size];
        for(k=0; k<previousSize; k++)
        {
            *(ptr+k)=*(var+k);
        }
    }
    void set_num(int v)
    {
        y=v;
    }
    void Shrink()   // decreases the size
    {
        int i;
        var=new int[size];
        for(i=0; i<top; i++)
        {
            var[i]=ptr[i];
        }

        size-=10;
        ptr=new int[size];

        for(i=0; i<top; i++)
        {
            ptr[i]=var[i];
        }
    }
    stack (const stack &s)
    {
        int i;
        top=s.top;
        ptr=new int[s.top];

        for(i=0; i<s.top; i++)
        {
            ptr[i]=s.ptr[i];
        }
    }
    double Similarity(stack s)
    {
        int i=top-1, j;
        double average_size,count=0;
        for( j=s.top-1; i>=0 && j>=0 ; i--, j--)
        {
            if(ptr[i]==s.ptr[j])
            {
                count++;
            }
        }
        cout<<"No. of elements matched : "<<count<<endl;
        average_size=((top+s.top)/2.0);
        cout<<"Average size = "<<average_size<<endl;
        cout<<"Similarity score = "<<endl;
        return (count/average_size);
    }
};

int main()
{
    stack mainstack ;
    int i,num,*pointer,x;
    cout<<"1: Push an element"<<endl;
    cout<<"2: Push an array"<<endl;
    cout<<"3: Push a stack"<<endl;
    cout<<"4: Pop"<<endl;
    cout<<"5: Top"<<endl;
    cout<<"6: Size"<<endl;
    cout<<"7: Similarity"<<endl;
    cout<<"8: Exit"<<endl;

    while(x!=8)
    {
        cout<<endl<<endl<<"Enter the no. associated with any of the above options :"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter a no. :"<<endl;
            cin>>num;
            mainstack.push(num);
        }
        if(x==2)
        {
            cout<<"Enter the number of elements in the Array:"<<endl;
            cin>>num;
            mainstack.set_num(num);
            pointer=new int[num];
            cout<<"Enter the elements :"<<endl;
            for(i=0; i<num; i++)
            {
                cin>>pointer[i];
            }
            mainstack.push(pointer);
        }
        if(x==3)
        {
            stack temp;
            cout<<"Enter the number of elements in the Stack :"<<endl;
            cin>>num;
            int x;
            while(num)
            {
                cin>>x;
                temp.push(x);
                num--;
            }
            mainstack.push(temp);
        }
        if(x==4)
        {
            cout<<mainstack.pop()<<endl;
        }
        if(x==5)
        {
            cout<<mainstack.Top()<<endl;
        }
        if(x==6)
        {
            cout<<mainstack.Size()<<endl;
        }
        if(x==7)
        {
            stack k_temp;
            cout<<"Enter the no. of elements :"<<endl;
            cin>>num;

            int x;
            while(num!=0)
            {
                cin>>x;
                k_temp.push(x);
                num--;
            }

            mainstack.Similarity(k_temp);
        }
        if(x==8)
        {
            int size=mainstack.Size();
            for(i=0; i<size; i++)
                cout<<mainstack.pop()<<endl;
        }
    }
    return 0;
}
