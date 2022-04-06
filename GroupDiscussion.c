#include <stdio.h>
#include <stdlib.h>

// Codeforces Beta Round #87 (Div. 1 Only) A Party
// Codeforces link:
// https://codeforces.com/contest/115/problem/A

// Wrapper function for findmother_
int findmother(int mother, int *parent);
// The recursive function findmother_ : Continue finding the parent until reaches -1, count the depth
int findmother_(int mother, int *parent, int counter);

int main(){
    int n, temp;
    scanf("%d",&n);

    // When he got no friends, just one group
    if(n==1){
        scanf("%d",&temp);
        printf("%d\n",1);
        return 0;
    }

    // Heap memory
    int *parent = (int *)calloc(n+1,sizeof(int));
    int *depth = (int *)calloc(n+1,sizeof(int));

    // Store who is the mother of each node
    for(int i=1; i<=n; i++){ 
        scanf("%d",&parent[i]);
    }

    // Find the depth of each node (start from 1)
    for(int i=1; i<=n; i++){
        depth[i]=findmother(parent[i],parent);
    }
    

    /*// === Debug === //
    printf("Parent Array:\n");
    for(int i=0; i<=n; i++){
        printf("%d ", parent[i]);
    }
    printf("\n");
    printf("Depth Array:\n");
    for(int i=0; i<=n; i++){
        printf("%d ", depth[i]);
    }
    printf("\n");
    */

   // The maximum value = The minimum number of group
    for(int i = 2; i<=n; i++){
        if(depth[1]<depth[i]){
            depth[1]=depth[i];
        }
    }

    // Print the answer :: minimum number of group
    printf("%d\n",depth[1]);
    
    // Release heap memory
    free(parent);
    free(depth);

    return 0;
}

// Wrapper function for findmother_
int findmother(int mother, int *parent){
    int counter = 1;
    if(mother==-1){
        return counter;
    }else{
        return findmother_(parent[mother],parent,counter);
    }

}

// The recursive function findmother_ : Continue finding the parent until reaches -1, count the depth
int findmother_(int mother, int *parent, int counter){
        counter++;
    if(mother==-1){
        return counter;
    }else{
        return findmother_(parent[mother],parent,counter);
    }
}