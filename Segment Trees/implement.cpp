#include<bits/stdc++.h>
using namespace std;


//index starts from one so that order is followed
//and s and e are the range of the indexes of given
//array and indexes from it are 0 to n-1
void buildTree(int *a,int s,int e,int *tree,int index){
    if(s==e){
        tree[index]=a[s];
        return;
    }

    //recursive case

    int mid=(s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
//in seg tree we store the ranges of the array
//which is 0 to n-1


//ss and se are ranges stored in seg. tree
//and these are in respect given array i.e will
//be 0 to n-1 where n is the size of given array
int query(int *tree,int ss,int se,int qs,int qe,int index){

    //complete overlap means range 3-4 and query 2-4
    if(ss>=qs and se<=qe){
        return tree[index];
    }

    //no overlap -- means range 1-2 and query 3-4
    if(qe<ss || qs>se){
        return INT_MAX;
    }

    //partial overlap -> means range 1-3 and query 1-2 
    int mid=(ss+se)/2;
    int left = query(tree,ss,mid,qs,qe,2*index);
    int right= query(tree,mid+1,se,qs,qe,2*index+1);

    return min(left,right);

}

//i is basically index of the actual array
//that needs to be updated
void update(int *tree,int ss,int se,int i,int increment,int index){

    //case where i is of of bounds
    if(i>se||i<ss){
        return;
    }

    //  if(ss==se&&ss==i){
    //     tree[index]+=increment;
    //     return;
    // }

    if(se==ss){
        tree[index]+=increment;
        return;
    }

    int mid=(ss+se)/2;
    update(tree,ss,mid,i,increment,2*index);
    update(tree,mid+1,se,i,increment,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);

}


void updateRange(int *tree,int ss,int se,int l,int r,int increment,int index){

    //order is important

    //case 1 out of bounds
    //same as update just checking for
    //range l to r
    if(l>se||r<ss){
        return;
    }

    //leaf node
    if(se==ss){
        tree[index]+=increment;
        return;
    }

    int mid=(ss+se)/2;
    updateRange(tree,ss,mid,l,r,increment,2*index);
    updateRange(tree,mid+1,se,l,r,increment,2*index+1);

    tree[index]=min(tree[2*index],tree[2*index+1]);

}



int main(){
    int a[]={1,3,2,-5,6,4};
    int n=6;

    int* tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);


    // for(int i=1;i<=13;i++){
    //     cout<<tree[i]<<" ";
    // }


    // update(tree,0,n-1,3,10,1);

    updateRange(tree,0,n-1,3,5,10,1);
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l,r,1)<<endl;
    }
}
