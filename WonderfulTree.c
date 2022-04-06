#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, temp;
    scanf("%d",&n);

    // Allocate Heap Memory
    int *numberofleaf = (int *)calloc(n+1,sizeof(int));
    int *parent = (int *)calloc(n+1,sizeof(int));
    int *haschild = (int *)calloc(n+1,sizeof(int));

    // Get the parent of node information
    // Count number of leaf node
    // Save the child record of the node
    for(int i=2; i<=n ; i++){ // Starting from Node 2 to n, because node 1 must be a root
        scanf("%d",&temp);    // Get the parent information
        numberofleaf[temp]++; // Parent's number of leaf +1
        parent[i]=temp;       // Save parent data for the node
        if(haschild[temp]==0){
            numberofleaf[parent[temp]]--;
            haschild[temp]=1;
        }
    }

    // === Debug === //
    //for(int i=0; i<=n; i++){printf("%d ", numberofleaf[i]);}printf("\n");
    // === Debug === //
    
    // Release heap memory
    free(parent);
    free(haschild);

    // === Check whether it is a wonderful tree === //
    if(numberofleaf[1]<=2){
        printf("No\n");
        free(numberofleaf);
        return 0;
    }

    for(int i=n; i>0; i--){
        if(haschild[i]==1){
            if(numberofleaf[i]<=2){
            printf("No\n");
            free(numberofleaf);
            return 0;
            }
        }
    }
    // === Check whether it is a wonderful tree === //
    
    printf("Yes\n");
    free(numberofleaf);

    return 0;
}

/*
9
1
1
1
1
2
6
6
6 */