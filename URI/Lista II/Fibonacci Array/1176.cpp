#include <stdio.h>

void fibonacci(int n);

int main(){
    int t, n;

    scanf("%d", &t);

    while(t!=0){
        scanf("%d", &n);

        if(0<=n<=60){
            fibonacci(n);
            t--;
        }
    }

}

void fibonacci(int n){
    long long int v[n];
    int i;

    v[0] = 0;
    v[1] = 1;

    for(i=2; i<=n; i++){
        v[i] = v[i-1] + v[i-2];
    }

    printf("Fib(%d) = %lld\n",n ,v[n]);

}
