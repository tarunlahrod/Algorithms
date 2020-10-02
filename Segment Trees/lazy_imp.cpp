

#include<bits/stdc++.h>
using namespace std;


int lazy[10000]={0};

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index){

    //before going down resolve the value if its exist

    if(lazy[index]!=0){
        tree[index]+=lazy[index];

        //non leaf nodes

        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }

        lazy[index]=0; //clear lazy value at current node
    }

    //base case
    //no overlap

    if(ss>r or l>se){
        return ;
    }

    //another case - complete overlap
    if(l<=ss and se<=r){
        tree[index]+=inc;

        //create a new lazy value of children node
        if(ss!=se){
            lazy[2*index]+=inc;
            lazy[2*index+1]+=inc;
        }

        return;
    }

    //recursive case
    //partial overlap
    int mid=(ss+se)/2;

    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);


    //update the tree[idx]

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;

     
}


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

int query(int *tree,int ss,int se,int qs,int qe,int index){

    //before going down resolve the value if its exist
     if(lazy[index]!=0){
        tree[index]+=lazy[index];

        //non leaf nodes

        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }

        lazy[index]=0; //clear lazy value at current node
    }


    
    //no overlap -- means range 1-2 and query 3-4
    if(qe<ss || qs>se){
        return INT_MAX;
    }

    //complete overlap means range 3-4 and query 2-4
    if(ss>=qs and se<=qe){
        return tree[index];
    }


    //partial overlap -> means range 1-3 and query 1-2 
    int mid=(ss+se)/2;
    int left = query(tree,ss,mid,qs,qe,2*index);
    int right= query(tree,mid+1,se,qs,qe,2*index+1);

    return min(left,right);

}



int main(){
    int a[]={1,3,2,-5,6,4};
    int n=6;

    int* tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);


    updateRange(tree,0,n-1,0,2,10,1);
    updateRange(tree,0,n-1,0,4,10,1);
    
    cout<<query(tree,0,n-1,1,1,1)<<endl;
    
    updateRange(tree,0,n-1,3,4,10,1);
    
    cout<<query(tree,0,n-1,3,5,1)<<endl;
    
}
