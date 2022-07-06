#include <stdio.h>
const int INF=100;
const int lamda=1;
const int dx[INF]={3,3};//0,1,2
const int dy=2;//0,1


double PY[INF];
double PXY[INF][INF];//P[Y的类型][目标X的j参数相等]
int X[INF][INF];
int Y[INF];
int XN,WN,aim[INF],NY[INF];


int MLE(){
    //PY赋值
    for(int i=0;i<dy;i++){
        int tot=0;
        for(int j=0;j<XN;j++){
            if(i==Y[j]){
                tot++;
            }
        }
        NY[i]=tot;
        PY[i]=tot*1.0/XN;
    }
    //PXY赋值
    for(int i=0;i<dy;i++){
        for(int j=0;j<WN;j++){
            int tot=0;
            for(int k=0;k<XN;k++){
                if(X[k][j]==aim[j]&&Y[k]==i){
                    tot++;
                }
            }
            PXY[i][j]=tot*1.0/NY[i];
        }
    }

    for(int i=0;i<dy;i++){
        double tot=PY[i];
        for(int j=0;j<WN;j++){
            tot*=PXY[i][aim[j]];
        }
        printf("Y=%d可能性：%lf\n",i,tot);

    }
    return 0;
}

int Bayes(){
    //PY赋值
    for(int i=0;i<dy;i++){
        int tot=0;
        for(int j=0;j<XN;j++){
            if(i==Y[j]){
                tot++;
            }
        }
        NY[i]=tot;
        PY[i]=(tot*1.0+lamda)/(XN+dy*lamda);
    }
    //PXY赋值
    for(int i=0;i<dy;i++){
        for(int j=0;j<WN;j++){
            int tot=0;
            for(int k=0;k<XN;k++){
                if(X[k][j]==aim[j]&&Y[k]==i){
                    tot++;
                }
            }
            PXY[i][j]=(tot*1.0+lamda)/(NY[i]+dx[j]*lamda);
        }
    }

    for(int i=0;i<dy;i++){
        double tot=PY[i];
        for(int j=0;j<WN;j++){
            tot*=PXY[i][aim[j]];
        }
        printf("Y=%d可能性：%lf\n",i,tot);

    }
    return 0;
    return 0;
}

int main(){
    freopen("in.txt","r",stdin);
    scanf("%d %d",&WN,&XN);
    for(int i=0;i<XN;i++){
        for(int j=0;j<WN;j++){
            scanf("%d",&X[i][j]);
        }
        scanf("%d",&Y[i]);
    }
    int tn;
    scanf("%d",&tn);
    while(tn--){
        for(int i=0;i<WN;i++){
            scanf("%d",&aim[i]);
        }
        printf("最大似然估计\n");
        MLE();
        printf("贝叶斯法\n");
        Bayes();
    }
    return 0;
}