#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
template<class Y>
class Myset
{
    private:
    Y* arr;
    int size;
    public:
    

    Myset()
    {
    	size =0;
    }
    Myset(int a)
    {
        size=a;
        arr=new Y[size];
    }
    //getting the elements from user
    void getsetelements()
    {
        cout<<"\n~~Enter the elements of set: ";
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        Duplicate();
        printSet();
    }
        //Removing Duplicates (if any)
    void Duplicate(){
    for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[i]==arr[j])
			{
			    size--;
				for(int k=i;k<size;k++)
				{		
				    arr[k]=arr[k+1];
			    }
			    i--;	
		    }
		}
	}

    }
    
    void printSet()
    {
        cout<<"The set is: {";
        if(size == 0)
        	cout<<" }";
        else
        	 for(int i=0;i<size;i++)
	        {
	            cout<<arr[i]<<((i==size-1)?'}':',');
	        }
    }
    //returning size of array
    int getcardinality()
    {
    	return size;
	}
	//function to show cardinality 
	void showcardinality()
	{
		cout<<"The cardinality of set entered is: "<<getcardinality();
	}
	//return changed size
	int changecardinality(int n)
	{
		size=n;
		return size;
	}
	//overloading for union
    Myset operator +(Myset obj2)

    {
    	Myset temp(size+obj2.getcardinality());
        
        for(int i=0;i<size;i++)
        {
           temp.arr[i]=arr[i]; 
            
        }
        int k=0;
        for(int j=size;j<temp.getcardinality();j++)
        {
            temp.arr[j]=obj2.arr[k];
            k++;
        }
        
        temp.Duplicate();
        
        return (temp);
    }
    //overloading for intersection
    Myset operator *(Myset obj2)
    {
    	
    	int n=(obj2.getcardinality()<size)?obj2.getcardinality() : size;
    	
    	{
		
    		Myset temp(n);
    		{
			int k=0;
    		for(int i=0;i<obj2.getcardinality();i++)
			{
				for(int j=0;j<size;j++)
				{
				  if(obj2.arr[i]==arr[j])
				   	 {
						temp.arr[k++]=obj2.arr[i];
						
				   	 } 
				}
			}
			temp.changecardinality(k);
			temp.Duplicate();
			
			return (temp);
			
        	}
	}
    }
    //overloading for difference
    Myset operator - (Myset obj2)
    {
    	int n=size;
    	int k=0;
    	Myset temp(n);
		for(int i=0;i<size;i++)
		{
			int flag=0;
			for(int j=0;j<obj2.getcardinality();j++)
			{
				if(arr[i]==obj2.arr[j])
				{
					flag=1;	
					break;		
				}
				
			}
			if(!flag)
				{
					temp.arr[k++]=arr[i];
				}
		 } 
    
    	temp.Duplicate();
    
    	temp.changecardinality(k);
    	return (temp);
	}
	//overloading for Symmetric Difference
	Myset operator ^ (Myset obj2)
	{
		int n=(obj2.getcardinality()>=size)?obj2.getcardinality() : size;
		Myset temp1(size+obj2.getcardinality());
		Myset temp2(n);
		Myset temp(n);
		temp1=*this +obj2;
		temp2=*this * obj2;
		temp=temp1-temp2;
		temp.Duplicate();
    	return (temp);
	}
	//overloading equality operator
	bool operator == (Myset obj2)
	{	
		
		if(size==obj2.getcardinality())
		{
			int flag1=0;
		    int flag2=1;
	      	for(int k=0;k<size&&flag2;k++)
			{
				flag1=0;
				for(int m=0;m<size;m++)
				{	
					if(arr[k]==obj2.arr[m])
			  	  {   
						 flag1=1;	
						 break; 
			   		}
		
				}
				if(flag1==0)
				{
					flag2=0;
				}
		}
		if(flag2)
			return true;
		else
			return false;
		}
		else
		{
			cout<<"\nThe size of both the sets is different ";
			return false;
		}
		
	}
	//overloading assignment operator
	Myset &operator = (const Myset &obj2)
	{
		size = obj2.size;
		arr = new Y[size];
		for(int i=0;i<size;i++)
		{
			arr[i]=obj2.arr[i];
		}
		Duplicate();
		return (*this);
	}
	void genpowerset(int size)
	{
		cout<<"The power set is : {";
		for(int i=0;i<pow(2,size);i++)
		{
			cout<<"{";
			for(int t=i,j=0;j<size;j++)
			{
				if(t&1)
				{
					cout<<arr[j]<<" ";
				}
				t=t>>1;
				
			}
			cout<<"}";
			cout<<((i<pow(2,size)-1)?',':'}');
		}
		cout<<"\n";
		cout<<"\nThe cardianality of power set is: "<<pow(2,size);	
	}

};
template <typename Y>
void func(Y typeVar)
{

int s,p,choice;
    
        	cout<<"\n~~Enter the size of set A: ";
        	cin>>s;
        	Myset<Y> obj1(s);
       		obj1.getsetelements();
       		
       		cout<<"\n~~Enter the size of set B: ";
       		cin>>p;
        	Myset<Y> obj2(p);
        	obj2.getsetelements();
        	
        	Myset<Y> obj3;	
            cout<<endl;
            
            char ans;
            cout<<endl;
       do
	   {
       	
        cout<<"\n~~~~~~~~~~~~~~~~~OPERATIONS ON SETS~~~~~~~~~~~~~~~~";
		cout<<endl;
		cout<<"\n~Enter the number to perform following operations: ";
		cout<<"\n";
		cout<<"\n~1.Union of two sets";
		cout<<"\n~2.Intersection of two sets";
		cout<<"\n~3.Difference of two sets";
		cout<<"\n~4.Symmetric Difference of two sets";
		cout<<"\n~5.Check the equality of two sets";
		cout<<"\n~6.Copy values of one set to another";
		cout<<"\n~7.Generate power set: ";
		cout<<"\n~8.Find cardinality of set.";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";          
		cout<<endl;
		cout<<"\n~~Enter the choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1:
				{
					obj3=obj1+obj2;  
					obj3.printSet();        //union operation
					break;
				}
			case 2:
				{
					
					obj3=obj1*obj2;
					obj3.printSet();         //intersection operation
					break;
				}
			case 3:
				{
					obj3=obj1-obj2;
					obj3.printSet();		    //Difference operation
					break;
				}
			case 4:
				{
					obj3=obj1^obj2;	
					obj3.printSet();		//Symmetric Difference operation
					break;
				}
			case 5:
				{
				 if(obj1==obj2)				//Assignment operation
        	   		 cout<<"->The sets are same.";
               	 else
             		cout<<"->The sets are not same";
             		break;
				}
			case 6:
				{
					obj3=obj2;	
					obj3.printSet();					//copying values of one set to another
					break;
				}
			case 7:
				{
					system("CLS");
					cout<<"\n ~a.Generate power set of set 'A'.(Press a)";
					cout<<"\n ~b.Generate power set of set 'B'.(Press b)";
					char subchoice;
					cout<<"\n->Enter your Response: ";   //generating power set 
					cin>>subchoice;
				
						switch(subchoice)
						{
							case 'a':
							{
								int size=obj1.getcardinality();
								obj1.genpowerset(size);
								break;
					   	    }
							case 'b':
							{
								int size=obj2.getcardinality();
								obj2.genpowerset(size);
								break;
							}
							default:
							{
								cout<<"->Enter correct choice!";
								
							}
							
					    } 
					    break;
	            }
	        case 8:
	        	{
	        		system("CLS");						
					//Finding cardinality of set
					cout<<"\n ~a.Find cardinality of set 'A'.(Press a)";
					cout<<"\n ~b.Find cardinality of set 'B'.(Press b)";
					char subchoice;
					cout<<"\n->Enter your Response: ";
					cin>>subchoice;
				
						switch(subchoice)
						{
							case 'a':
							{
								obj1.showcardinality();
								
								break;
					   	    }
							case 'b':
							{
								obj2.showcardinality();
								
								break;
							}
							default:
							{
								cout<<"\n->Enter correct choice!";
								
							}
							
					    } 
					    break;
				}
	            
	        default:
	            {
	            	cout<<"Enter correct choice!!";
	            	break;
				}
			}
			
			cout<<"\nDo you wish to continue(Press 'Y' for YES and 'N' for NO.)";
			cout<<"\nChoice->";
			cin>>ans;
			cout<<endl;
			 system("CLS");
   	 }
   	
   	 while(ans=='Y'||ans=='y');
   	 
   }

    int main()
    {
      int choice;
   	
   	 cout<<"\nEnter the datatype on which operations are to be performed: ";
   	 cout<<"\n~1.Integers (Press 1)";
 	 cout<<"\n~2.Characters (Press 2)";
	 cout<<"\n~3.Double (Press 3)" ; 
	 cout<<"\nChoice-> "; 	 
   	 cin>>choice;
   	 
   	 int i;
   	 char c;
   	 double d;
   	 
   	 switch(choice)
   	 {
   	 	case 1: func(i);
   	 		break;
   	 			
		case 2: func(c);
   	 		break;
   	 		
   	 	case 3: func(d);
   	 		break;
   	 	default:
   	 		cout<<"Enter correct choice";
		}  
   	  
   	 return 0;
}

