#include<iostream>
using namespace std;
class BinaryHeap
{
	//the private attributes
	private:
	int mSize, cSize, *bhArr;
	int Arr[50];
	//the public attributes
	public:
	BinaryHeap()
	{
		mSize=50;
		cSize=0;
	}
	//the left , right and parent functions
	int right(int i){return ((2*i)+2);}
	int parent(int i){return ((i-1)/2);}
	int left(int i){return ((2*i)+1);}
	// the insert function
	void insert(int data)
	{
		if(cSize==0)
		{
			cSize++;
			Arr[0]=data;
		}
		else if(cSize==mSize)
		{
			cout<<"can't insert anymore elements";
			return;
		}
		else
		{
			if(data<=Arr[0])
			{

				for(int i=cSize;i>0;i--)
				{
					Arr[cSize+1]=Arr[cSize];
				}
				Arr[0]=data;
			}
			else
			{
				Arr[cSize]=data;
				int l=cSize;
				while(Arr[parent(l)]>Arr[l] || parent(l)!=cSize/2)
				{
					int temp;
					temp = Arr[l];
					Arr[l] = Arr[parent(l)];
					Arr[parent(l)] = temp;
					l=parent(l);
				}
			}
			cSize++;
		}
	}
	//getting the minimum value
	int getMin(){return Arr[0];}
	//extratng the minumum
	int extractMin()
	{
		if(cSize==0)
		{
			cout<<"it's an empty heap";
			return NULL;
		}
		else if(cSize == 1)
		{
			cSize--;
			return Arr[0];
		}
		else
		{
			int temp = Arr[0];
			for(int i=0;i<cSize;i++)
			{
				Arr[i]=Arr[i+1];
			}
			cSize--;
			return temp;
		}
	}
	//the derease the key
	void decreaseKey(int i, int new_val)
	{
		Arr[i]=new_val;
		while((Arr[parent(i)]>Arr[i] && )||(Arr[parent(i)]<Arr[i] && ) )
		{
		}
	}
	//the display function
	void display()
	{
		if(cSize==0)
		{
			cout<<"empty heap"<<endl;
			return;
		}
		for(int i=0;i<cSize;i++)
		{
			cout<<Arr[i]<<",";
		}
		cout<<endl;
	}

//the main function
int main()
{
	BinaryHeap bh;
	bh.display();
	for(int i=0;i<10;i++)
	{
		bh.insert(i+1);
	}
	bh.insert(-3);
	bh.display();
	return 0;
}
