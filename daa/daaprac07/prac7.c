void nextVertex(int c[],int k){
    do{
        c[k]=(c[k]+1) % (n);
        printf("k=%d c[%d]=%d\n",k,k,c[k]);
        if(c[k]==0)
            return;
        int j;
        if(adj[c[k]][c[k-1]]!=0){
            for(j=0;j<=k-1;j++){
                if(c[j]==c[k])
                    break;
            } 
            if(j==k){
                if(k<n-1 || (k==n-1 && adj[c[n-1]][c[0]]!=0)){
                        //printf("Found for k=%d, c[%d]=%d n=%d\n",k,k,c[k],n);
                        return;
                    }    
                }        
        }
    }while(1);
}
void hamiltonian(int c[],int k){
    if(k==0){
        c[k]=0;
        k++;
    }
    do{
        nextVertex(c,k);
        if(c[k]==0){
            return;
        }
        if(k==n-1){
            printf("Cycle:::: ");
            for(int i=0;i<n;i++)
                printf("%d ",c[i]);
            printf("%d ",c[0]);    
            printf("\n");    
        }else{
            hamiltonian(c,k+1);
        }
    }while(1);
}

int main(){
    int c[n]={0,0,0,0,0};
    int k=0;
    hamiltonian(c,k);
    return 0;
}