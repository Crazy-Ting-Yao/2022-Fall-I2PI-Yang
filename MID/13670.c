#include<stdio.h>
#include<stdlib.h>
int check_sum(char **a){//檢查數量函式
    int black=0,white=0;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(a[i][j]=='1'){
                black++;
            }
            else if(a[i][j]=='2'){
                white++;
            }
        }
    }
    int diff = black-white;
    if(diff==1){
        return 1;//最後一手是黑子
    }
    if(diff==0){
        return -1;//最後一手是白子
    }
    else{
        return 0;//數量錯誤
    }
}
int check_line(int **line,char **a,char color,int x,int y){//檢查有沒有連線
    int bigflag=0;//只要有連線，就會是1，周圍都沒有連線的點回傳0
    int counti=0;
    for(int i=x-4;i<=x+4;i++){//檢查直的
        if(i>=0){
            if(i==15){
                break;
            }
            if(a[i][y]==color){
                counti++;
                if(counti>=5){
                    break;
                }
            }
            else{
                counti=0;
            }
        }
    }
    if(counti>=5){
        if(color=='1'){
            line[x][y]++;//過這個點有幾個線（黑子用正的）
        }
        else line[x][y]--;//過這個點有幾個線（白子用負的）
        bigflag=1;
    }
    counti=0;
    for(int i=y-4;i<=y+4;i++){
        if(i>=0){
            if(i==15){
                break;
            }
            if(a[x][i]==color){//檢查橫的
                counti++;
                if(counti>=5){
                    break;
                }
            }
            else{
                counti=0;
            }
        }
    }
    if(counti>=5){
        if(color=='1'){
            line[x][y]++;//過這個點有幾個線（黑子用正的）
        }
        else line[x][y]--;//過這個點有幾個線（白子用負的）
        bigflag=1;
    } 
    counti=0;
    for(int i=-4;i<=4;i++){
        if(x+i>=0&&y+i>=0){
            if(x+i>=15||y+i>=15){//檢查左上到右下方向的
                break;
            }
            if(a[x+i][y+i]==color){
                counti++;
                if(counti>=5){
                    break;
                }
            }
            else{
                counti=0;
            }
        }
    }
    if(counti>=5){
        if(color=='1'){
            line[x][y]++;//過這個點有幾個線（黑子用正的）
        }
        else line[x][y]--;//過這個點有幾個線（白子用負的）
        bigflag=1;
    }  
    counti=0; 
    for(int i=-4;i<=4;i++){
        if(x+i>=0&&y-i<15){
            if(x+i>=15||y-i<0){//檢查右上到左下方向的
                break;
            }
            if(a[x+i][y-i]==color){
                counti++;
            }
            else{
                counti=0;
            }
        }
    }
    if(counti>=5){
        if(color=='1'){
            line[x][y]++;//過這個點有幾個線（黑子用正的）
        }
        else line[x][y]--;//過這個點有幾個線（白子用負的）
        bigflag=1;
    }  
    return bigflag;//0->此點沒有連線、1->此點有連線
}
int check_black_sum(int **line,char **a){
    int bigflag=0;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(a[i][j]=='1'){
                bigflag+=check_line(line,a,'1',i,j);//遇到黑子就看有沒有連線
            }
        }
    }
    return bigflag;
}
int check_white_sum(int **line,char **a){
    int bigflag=0;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(a[i][j]=='2'){
                bigflag+=check_line(line,a,'2',i,j);//遇到白子就看有沒有連線
            }
        }
    }
    return bigflag;
}
int find_max(int **line,char color,char **a){
    int max=1;
    int con[5]={0};//儲存連線數的點數（例如過line[0][0]有2條線，就在con[2]++、過line[6][6]有4條線，就在con[4]++
    int index_x;//記錄有過多於一條線的點位置、因為他必是最後一步
    int index_y;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(color=='1'){
                if(line[i][j]){
                    con[line[i][j]]++;
                    if(line[i][j]>max){
                        max=line[i][j];
                        index_x=i;
                        index_y=j;
                    }
                }
            }
            else{
                if(line[i][j]){
                    con[-line[i][j]]++;//因為白子是負的，所以要變號
                    if((-line[i][j])>max){
                        max=(-line[i][j]);
                        index_x=i;
                        index_y=j;
                    }
                }
            }
        }
    }
    if(max==1){
        if(con[1]>9){
            return 0;//理論上每個點都只有一條線的話，不可能有多餘9個點過線（最多就是9個連在一起然後最後一步在正中間）
        }
        else return 1;
    }
    else{
        for(int j=2;j<max;j++){
            if(con[j]){
                return 0;//最後一步只有一個，也就是有過多於一條線的點位置只有一個，如果有多就是違規
            }
        }
        if(con[max]!=1){
            return 0;//最後一步只有一個
        }
        a[index_x][index_y]=0;//如果拿掉最後一步，那不應該有任何線成立
        if(color=='1'){
            if(check_black_sum(line,a)){
                return 0;//有任何線成立，報錯
            }
            else{
                return 1;
            }
        }
        else{
            if(check_white_sum(line,a)){
                return 0;//有任何線成立，報錯
            }
            else{
                return 1;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    char** c = calloc(sizeof(char*),15);
    int** line=calloc(sizeof(int*),15);
    for(int i=0;i<15;i++){
        c[i] = calloc(sizeof(char),16);
        line[i] = calloc(sizeof(int),15);
    }
    while(T--){
        for(int i=0;i<15;i++){
            scanf("%s",c[i]);
        }
        int ch=check_sum(c);
        if(!ch){
            printf("No\n");
            continue;
        }
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                line[i][j]=0;
            }
        }
        if(ch==1){//如果最後一步是黑子
            if(check_white_sum(line,c)){
                printf("No\n");//白子有連線，那應該提早結束，報錯
                continue;
            }
            if(check_black_sum(line,c)){//黑子有連線
                if(find_max(line,'1',c)){//黑子有連線
                    printf("Yes\n");
                    continue;
                }
                else{
                    printf("No\n");
                    continue;
                }
            }
            else{
                printf("Yes\n");//黑子白子都沒有連線，合理
                continue;
            }
        }
        else if(ch==-1){
            if(check_black_sum(line,c)){
                printf("No\n");
                continue;
            }
            else if(check_white_sum(line,c)){
                if(find_max(line,'2',c)){
                    printf("Yes\n");
                    continue;
                }
                else{
                    printf("No\n");
                    continue;
                }
            }
        }
    }
    for(int i=0;i<15;i++){
        free(c[i]);
        free(line[i]);
    }
    free(c);
    free(line);
    return 0;
}