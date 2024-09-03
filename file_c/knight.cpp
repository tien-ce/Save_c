#include"knight.h"
using namespace std;
int strlen(char x[]){
int dem=0;	
while(x[dem]!='\0'){
dem++;	
}
return dem;
}
int kiemtrasonguyento(int x){
int  kiemtra=1;
if(x==1){
kiemtra=0;	
}
else if(x==2){
kiemtra=1;	
}
else{
for(int i=2;i<x;i++){
if(x%i==0){
kiemtra=0;	
}
}
}
return kiemtra;
}
int chuyendoi1(char x1[],int x[]){
int dem;
int n=0;
for(int i=0;i<strlen(x1);i++){
dem=0;	
if (x1[i]!=' '&&x1[i]!=','){	
do{
dem++;	
}	
while(x1[i+dem]!=' ' &&  x1[i+dem]!='\0'&&x1[i+dem]!=',');    	
int luythua[20];
	luythua[0]=1;
	for(int j=1;j<10;j++){
	luythua[j]=10*luythua[j-1];	
	}
if(x1[i]!='-'){
if(dem==1){
x[n]=0;	
x[n]+=x1[i]-48;	
}
else{	
x[n]=0;	
for(int j=0;j<dem;j++){
x[n]+=(x1[j+i]-48)*luythua[dem-j-1];		
}
}
}
else{
int v=1;	
x[n]=0;
while(x1[i+v]!=' '&&x1[v+i]!='\0'&&x1[v+i]!=','){
x[n]=x[n]*10+(x1[v+i]-48);
v++;	
}
x[n]=-x[n];
}
i+=dem-1;
n++;
}
}
return n;
}
void chuyendoi(char x[], int &x1) {
    int dem = 0, dau = 1;
    if (x[0] == '-') {
        dau = -1;
        x++;
    }
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] != ' ' && x[i] != ',') {
            do {
                dem++;	
            } while (x[i + dem] != ' ' && x[i + dem] != '\0' && x[i + dem] != ',');    			
            int luythua[20];
            luythua[0] = 1;
            for (int j = 1; j < 10; j++) {
                luythua[j] = 10 * luythua[j - 1];	
            }
            x1 = (x[i] - 48) * luythua[dem - 1];	
            for (int j = 1; j < dem; j++) {
                x1 += ((x[i + j]) - 48) * luythua[dem - j - 1];	
            }
            x1 *= dau; 
            i += dem;	
        } 
		else {
            continue;
        }
    }
}	
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void xoaxuongdong(char x[]){
if(x[strlen(x)-1]=='\n'){
x[strlen(x)-1]= '\0';	
}	
}
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
char tenFile[100];
char filecandung_1[100][100];
for(int i=0;i<100;i++){
tenFile[i]=file_input[i];	
}
tenFile[file_input.length()]='\0';	
xoaxuongdong(tenFile);
char chisohiepsi1[100];
char masukien1[100];
char filecandung[100];
int chisohiepsi[100];
int masukien[100];
int solangap=0;

FILE*f;
f=fopen(tenFile,"r");
if(f==NULL){
printf("LOI INPUT");
exit(1);	
}
fgets(chisohiepsi1,100,f);
xoaxuongdong(chisohiepsi1);
chisohiepsi1[strlen(chisohiepsi1)]='\0';
fgets(masukien1,100,f);
xoaxuongdong(masukien1);
masukien1[strlen(masukien1)]='\0';
fgets(filecandung,100,f);
xoaxuongdong(filecandung);
filecandung[strlen(filecandung)]='\0';
fclose(f);
// TEST THU
/*
printf("chi so hiep si:%s",chisohiepsi1);
printf("\ncac su kien dien ra lan luot:%s",masukien1);
printf("\nfile can dung:%s",filecandung);
*/
int dem=0;
int o[100];
int n;
int m=0;
int h;
int c13[100][100];
// FILE CAN DUNG
for(int i=0;i<strlen(filecandung);i++){
h=0;	
n=0;
if(filecandung[i]==','){
m++;
continue;	
}
do{
filecandung_1[m][n]=filecandung[h+i];
h++;
n++;
}
while(filecandung[h+i]!=',' && filecandung[h+i]!='\0');	 
i+=h-1;
}
n=0;
m=0;

// CHUYEN DOI CHI SO HIEP SI
for(int i=0;i<strlen(chisohiepsi1);i++){
	if (chisohiepsi1[i]!=' '){
	do{
	dem++;	
	}		
	while(chisohiepsi1[i+dem]!=' '&& chisohiepsi1[i+dem]!='\0');    	
	if(dem==1){
	chisohiepsi[n]=chisohiepsi1[i]-48;
	n++;
	}
	else{	
	int luythua[20];
	luythua[0]=1;
	for(int j=1;j<10;j++){
    luythua[j]=10*luythua[j-1];	
	}
	chisohiepsi[n]=(chisohiepsi1[i]-48)*luythua[dem-1];	
	for(int j=1;j<dem;j++){
	chisohiepsi[n]+=((chisohiepsi1[i+j])-48)*luythua[dem-j-1];	
	}
	n++;
	i+=dem-1;	
	}
	dem=0;	
	}
	else{
	continue;
	}
	}
	//TEST THU	
	
	/*
	for(int i=0;i<n;i++){
	printf("%d \t",chisohiepsi[i]);	
	}
	*/
	dem=0;
	// CHUYEN DOI MA SU KIEN
	int dem_13=0;
	for(int i=0;i<strlen(masukien1);i++){		
	if (masukien1[i]!=' '){
	do{
	dem++;	
	}	
	while(masukien1[i+dem]!=' '&& masukien1[i+dem]!='\0');    
	if(dem==1){
	masukien[m]=masukien1[i]-48;
	m++;
	}
	else{	
	int luythua[20];
	luythua[0]=1;
	for(int j=1;j<10;j++){
	luythua[j]=10*luythua[j-1];	
	}
	if(masukien1[i]=='1' && masukien1[i+1]=='3'){
	masukien[m]=13;
	o[dem_13]=0;
    do{ 	
    c13[dem_13][o[dem_13]]=masukien1[i+2+o[dem_13]]-48;
    /*
	cout<<"odem13="<<o[dem_13]<<"\n";     
    cout<<"nam"<<c13[dem_13][o[dem_13]]<<"\n"; 
	*/
	o[dem_13]++;
	}
    while(masukien1[i+2+o[dem_13]]!=' '&& masukien1[i+2+o[dem_13]]!='\0');
	dem_13++;
	}
	else{		
	masukien[m]=(masukien1[i]-48)*luythua[dem-1];
	for(int j=1;j<dem;j++){
	masukien[m]+=((masukien1[i+j])-48)*luythua[dem-j-1];	
	} 
    }
	m++;
	i+=dem-1;	
	}
	dem=0;	
	}
	dem=0;  
}
//TEST THU
/*
	printf("\n cac su kien lan luot \n");
 */
    for(int i=0;i<m;i++){
    	continue;
	}
	 HP=chisohiepsi[0];
     level=chisohiepsi[1];
	 remedy=chisohiepsi[2];
	 maidenkiss=chisohiepsi[3];
	 phoenixdown=chisohiepsi[4];
	 rescue=-1;
	int snt=kiemtrasonguyento(HP);
	// KIEM TRA SO NGUYEN TO
	int maxhp=HP;
	int level0,b;
	int n1,s1=0;
	int tihon=0,k=0,level_1;
	int ech=0,k1=0;
    char dong1[100];
char dong2[100];	
int nam[100];
int sonam;
int dem_131;
int max2_3;
int max2_3i;
int maxi2,max2;
int mini2;
int min2;
int maxi,max;
int mini,min;
int mini2_3;
int min2_3;
int kiemtra;
int demlan13=0;
int demlan18=0;
	//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	if(HP==999){
	for(int i=1;i<=m;i++){	
    // ATHUR dieu kien eo chiu noi truoc 
    if(masukien[i-1]<=5&&masukien[i-1]>=1){
    level+=1;	
	}
	else if(masukien[i-1]==6||masukien[i-1]==7){
	level+=2;
	}
	if(i<=m-1){
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue); 
	}
   
    }
     rescue=1;
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue); 
    return;		   
    
}
    
	for(int i=1;i<=m;i++){
	int b=i%10;
	level0=i>6?(b>5?b:5):b;	
	if(masukien[i-1]==0){
	rescue=1;	
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
	return;			
	}
	if(masukien[i-1]<=7&&masukien[i-1]>=1){
	if(snt==1){
	if(masukien[i-1]<=5&&masukien[i-1]>=1){
	
	level+=1;	
	}
    
    else{
    level+=2;	
	}
	if(level>10){
	level=10;	
	}
	}
	else{	
	if (masukien[i-1]<=5 && masukien[i-1]>=1){
	// GIAO TRANH	
		float basedamage;
		switch(masukien[i-1]){
		case 1:
		basedamage=1;
		break;
		case 2:
		basedamage=1.5;
		break;
		case 3:
		basedamage=4.5;
		break;
		case 4:
		basedamage=7.5;
		break;
		case 5:
	    basedamage=9.5;
		break;	
		}
	float damage=basedamage*level0*10;
	if (level>level0){
	level+=1;
	rescue=-1;
	if(level>10){
	level=10;	
	}	
	}
	else if(level==level0) {
	rescue=-1;	
	}
	else{
	HP-=damage;
	if (HP>0){
	rescue=-1;	
	}
	else{
	if(phoenixdown>=1){
	phoenixdown-=1;
	HP=maxhp;
	tihon=0;
	ech=0;
	rescue=-1;
	}
	else{
	rescue=0;
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue);	
    return;
	}	
	}	
	}		
	}	
  if(masukien[i-1]==6 && tihon==0 && ech==0){
  	// GIAO TRANH VOI PHU THUY SHAMAN
  	if(level>level0){
	level+=2;
	if(level>10){
	level=10;	
	}
	rescue=-1;	
	}
	else if(level==level0){
	rescue=-1;	
	}
	else{		
    k=i;
    tihon=1;
	if(remedy>=1){
	remedy-=1;
	tihon=0;
	rescue=-1;	
	}
	else{
	k=i;	
	tihon=1;
	if(HP<5){
	HP=1;	
	}
	else{
	HP/=5;	
	}
	rescue=-1;	
	}	
	}
  }
    if(tihon==1){
    if(remedy>=1){
    tihon=0;
    remedy-=1;
	rescue=-1;
	continue;	
	}
    if(masukien[i-1]==6 || masukien[i-1]==7){
    rescue=-1;		
	}
	if(i-k>=3){	
	HP*=5;
	if(HP>maxhp){
    HP=maxhp;	
	}
	tihon=0;
	rescue=-1;	
	}
	}
	if(masukien[i-1]==7&&ech==0&&tihon==0){
	// GIAO TRANH VOI VAJSH
	if(level>level0){
	level+=2;
	if(level>10){
	level=10;
	rescue=-1;	
	}	
	}
	else if(level==level0){
	rescue=-1;	
	}
	else{
	ech=1;
	if(maidenkiss>=1){
	maidenkiss-=1;
	ech=0;
	rescue=-1;	
	}
	else{
	ech=1;
	k1=i;
	level_1=level;
	level=1;
	rescue=-1;	
	}	
	}	
	}
	if(ech==1){
	if(maidenkiss>=1){
    maidenkiss-=1;
	level=level_1;
	rescue=-1;	
	continue;
	}	
	if (masukien[i-1]==7 || masukien[i-1]==6){
	rescue=-1;	
	}
	if(i-k1>=3){	
	level=level_1;
	ech=0;
	rescue=-1;	
	}
}
}
}
int a[100];
int n=0;
for(int j=99;j>10;j--){
if(j%2!=0){
a[n]=j;	
n++;
}
else{
continue;	
}
}
if(masukien[i-1]==11){
s1=0;	
n1=(((level + phoenixdown)%5)+1)*3;	
for(int j=0;j<n1;j++){
s1+=a[j];	
}
HP+=(s1%100);
do{
HP++;
}
while(kiemtrasonguyento(HP)==0);
rescue=-1;
if(HP>maxhp){
HP=maxhp;	
}
}
int sofibonacci[1000];
sofibonacci[0]=1;
sofibonacci[1]=1;
for(int j=2;j<1000;j++){
sofibonacci[j]=sofibonacci[j-1]+sofibonacci[j-2];	
}
if(masukien[i-1]==12){
if(HP>1){
for(int j=0;j<1000;j++){
if (HP-sofibonacci[j]>=0 && HP-sofibonacci[j+1]<=0){
HP=sofibonacci[j];
rescue=-1;
break;	
}	
}
}
else{
rescue=-1;
}
if(HP>maxhp){
HP=maxhp;	
}
}
if(masukien[i-1]==13){
demlan13++;
FILE *fg;	
fg=fopen(filecandung_1[0],"r");
if(fg==NULL){
cout<<"ERROL";	
}
fgets(dong1,100,fg);
xoaxuongdong(dong1);
fgets(dong2,100,fg);
xoaxuongdong(dong2);
dong2[strlen(dong2)]='\0';
fclose(fg);
// CHUYEN DOI NAM
int l=0;
int soday=chuyendoi1(dong2,nam);
sonam=0;
int luythua[100];
luythua[0]=1;
for(int j=1;j<10;j++){
	luythua[j]=10*luythua[j-1];	
	}
	
for(int j=0;j<strlen(dong1);j++){
if(dong1[j]!=' '&&dong1[j]!='\0'){
sonam+=(dong1[j]-48 )* luythua[strlen(dong1)-j-1]; 
}
}
int x[100];
for(int j=0;j<sonam;j++){
//TEST
/*
cout<<nam[j]<<"\t";
*/	
if(nam[j]<0){
x[j]=-nam[j];
x[j]=(17*x[j]+9)%257;	
}
else{
x[j]=(17*nam[j]+9)%257;	
}
}
//TEST
/*
for(int j=0;j<sonam;j++){
cout<<x[j]<<"\t";	
}
cout<<"\n";
*/
if(demlan13==1){
// maxi mini :vi tri cuoi cung luon ,nho nhat. 
//maxi2 vitri lon nhat day x  mini2 vitri nho nhat day x
max2_3=x[0];
max2_3i=0;
maxi2=0;
max2=x[0];
mini2=0;
min2=x[0];
maxi=0,max=nam[0];
mini=0,min=nam[0];
mini2_3=0;
min2_3=x[0];
kiemtra=0;
for(int j=0;j<sonam;j++){
if(nam[j]>=max){
maxi=j;	
max=nam[maxi];
}	
}
for(int j=0;j<sonam;j++){
if(nam[j]<=min){
mini=j;	
min=nam[mini];
}	
}
for(int k=1;k<sonam;k++){
if(x[k]>max2){
maxi2=k;
max2=x[maxi2];
}
}		
for(int k=1;k<sonam;k++){
if(x[k]<min2){
mini2=k;
min2=x[mini2];
}	
}
int demmax=0;
for(int j=0;j<sonam;j++){
	if(nam[j]==max){
	demmax++;
	}
}
int demmin=0;
for(int j=0;j<sonam;j++){
	if(nam[j]==min){
	demmin++;
	}
}
int max2_31=x[0];
for(int j=0;j<3;j++){
// test
/*
cout<<"max_231="<<max2_31<<"\n";
*/	
if(x[j]>max2_31){
max2_31=x[j];	
}	
}
// TEST
/*
cout<<"max_231="<<max2_31<<"\n";
*/
max2_3=-999;
max2_3i=0;
kiemtra=0;
for(int j=0;j<(sonam>3?3:sonam);j++){
if(x[j]==max2_31){
continue;	
}
if(x[j]>max2_3){
kiemtra=1;	
max2_3i=j;
max2_3=x[max2_3i];	
}
}
}
for(int j=0;j<=1000;j++){

if(c13[dem_131][j]==1){
HP-=(maxi+mini);
	if(HP>maxhp){
	HP=maxhp;	
}
if (HP>0){
	rescue=-1;	
	}
	else{
	if(phoenixdown>=1){
	phoenixdown-=1;
	HP=maxhp;
	tihon=0;
	ech=0;
	rescue=-1;
	}
	else{
	rescue=0;
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue);	
	return;
	}
}
}
else if(c13[dem_131][j]==2){	
int xacthuc=0;
int vitri=0,giatri=0;
if(nam[0]>nam[1]){
vitri=0;
giatri=nam[0];
xacthuc++;
}
if(nam[soday-1]>nam[soday-2]){
vitri=soday-1;
giatri=nam[soday-1];	
xacthuc=1;
}
if(nam[0]>nam[1]){
xacthuc=1;	
vitri=0;
giatri=nam[0];	
}
for(int k=1;k<soday-1;k++){
if(nam[k]>nam[k+1] && nam[k]>nam[k-1]){
vitri=k;
giatri=nam[k];
xacthuc++;	
}
if(nam[k]==nam[k-1] ){
xacthuc=0;	
}	
if(nam[0]>nam[1]&&((nam[k]>nam[k+1] && nam[k]>nam[k-1])||nam[soday-1]>nam[soday-2])){
xacthuc=0;	
}
}
if(xacthuc==1){
HP-=(vitri+giatri);
}
else{
HP+=5;
}
if (HP>0){
	rescue=-1;	
	}
	else{
	if(phoenixdown>=1){
	phoenixdown-=1;
	HP=maxhp;
	tihon=0;
	ech=0;
	rescue=-1;
	}
	else{
	rescue=0;
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue);	
	return;
	}
}
}
else if(c13[dem_131][j]==3){	
//TEST
/*
cout<<"maxi2="<<maxi2<<",mini2="<<mini2<<"\n";
*/
HP-=(maxi2+mini2);	
if(HP>maxhp){
	HP=maxhp;	
	}
	if (HP>0){
	rescue=-1;	
	}
	else{
	if(phoenixdown>=1){
	phoenixdown-=1;
	HP=maxhp;
	tihon=0;
	ech=0;
	rescue=-1;
	}
	else{
	rescue=0;
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue);	
	return;
	}
}
}
 else if(c13[dem_131][j]==4){
if(kiemtra==1){	
//TEST
/*
cout<<"max2_3i="<<max2_3i<<",max2_3="<<max2_3<<"\n";
*/
HP-=(max2_3+max2_3i);
if(HP>maxhp){
	HP=maxhp;	
	}	
}
else{
HP+=12;
if(HP>maxhp){
	HP=maxhp;	
	}	
}
if (HP>0){
	rescue=-1;	
	}
	else{
	if(phoenixdown>=1){
	phoenixdown-=1;
	HP=maxhp;
	tihon=0;
	ech=0;
	rescue=-1;
	}
	else{
	rescue=0;
	display(HP,level,remedy,maidenkiss,phoenixdown,rescue);	
	return;
	}
}

}
else{
break;	
}
if(HP>maxhp){
HP=maxhp;	
}
//TEST
/*	
display(HP,level,remedy,maidenkiss,phoenixdown,rescue);	
*/
}
dem_131++;
if(HP>maxhp){
HP=maxhp;	
}
}
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
else if(masukien[i-1]==15){
	// NHAT DUOC REMEDY
	remedy++;
	if(tihon==1){
	remedy-=1;
	tihon=0;	
	HP*=5;
	}
	if(remedy>99){
	remedy=99;	
	}	
}
else if(masukien[i-1]==16){
// NHAT DUOC MAIDENKISS
maidenkiss++;
if(ech==1){
maidenkiss-=1;
ech=0;	
level=level_1;
}
if(maidenkiss>99){
   maidenkiss=99;
}	
}
else if(masukien[i-1]==17){
// NHAT DUOC PHOENIX
phoenixdown+=1;
if(phoenixdown>99){
phoenixdown=99;	
}	
}
else if(masukien[i-1]==19&&solangap==0){
solangap=1;	
int sothuoc;
char luachon[100];
int row;
char luachon_1[100];
int col;
char sv[100][100];
int sv_1[100][100];	
//ASCLEPIUS
f=fopen(filecandung_1[1],"r");
if(f==NULL){
cout<<"ERROL";	
}
fgets(luachon,100,f);
xoaxuongdong(luachon);
chuyendoi(luachon,row);
fgets(luachon_1,100,f);
xoaxuongdong(luachon_1);
chuyendoi(luachon_1,col);
for(int k=0;k<row;k++){
fgets(sv[k],100,f);
xoaxuongdong(sv[k]);
}
fclose(f);
for(int j=0;j<row;j++){
chuyendoi1(sv[j],sv_1[j]);
}
for(int j=0;j<row;j++){	
for(int k=0;k<col;k++){	
if(sv_1[j][k]==16&&sothuoc<3){
sothuoc++;	
remedy+=1;
if(remedy>99){
remedy=99;	
}
if(tihon==1){
remedy-=1;
HP*=5;
tihon=0;	
}	
}
else if(sv_1[j][k]==17&&sothuoc<3){
sothuoc++;
maidenkiss+=1;

if(maidenkiss>99){
maidenkiss=99;	
}
if(ech==1){
maidenkiss-=1;
ech=0;	
}
}
else if(sv_1[j][k]==18&&sothuoc<3){	
sothuoc++;	
phoenixdown+=1;
if(phoenixdown>99){
phoenixdown=99;	
}	
}
else{
continue;	
}
}	
sothuoc=0;
}	
}

if(masukien[i-1]==18&&demlan18==0){
demlan18++;	
FILE *f;
int dem_m,dem_e,dem_r,dem_l,dem_i,dem_n;
char n_18[100];
char n_19[100][100];	
int n_181;
	f=fopen(filecandung_1[2],"r");
	fgets(n_18,100,f);
	xoaxuongdong(n_18);
	chuyendoi(n_18,n_181);
	for(int l=0;l<n_181;l++){
	dem_m=0,dem_e=0,dem_r=0,dem_l=0,dem_i=0,dem_n=0;	
	fgets(n_19[l],100,f);
	xoaxuongdong(n_19[l]);	
    for(int j=0;j<strlen(n_19[l]);j++){
	if(n_19[l][j]=='m'||n_19[l][j]=='M'){		
	dem_m++;	
	if(n_19[l][j+1]=='e'&&n_19[l][j+2]=='r'&&n_19[l][j+3]=='l'&&n_19[l][j+4]=='i'&&n_19[l][j+5]=='n'){
	HP+=3;
	break;	
	}
	}
	else if(n_19[l][j]=='e'||n_19[l][j]=='E'){
    dem_e++;	
	}
	else if(n_19[l][j]=='r'||n_19[l][j]=='R'){
    dem_r++;	
	}
	else if(n_19[l][j]=='l'||n_19[l][j]=='L'){
    dem_l++;	
	}
	else if(n_19[l][j]=='i'||n_19[l][j]=='I'){
    dem_i++;	
	}
	else if(n_19[l][j]=='n'||n_19[l][j]=='N'){
    dem_n++;	
	}
	else{
	continue;	
	}
	}
	if(dem_m>1){
	dem_m=1;	
	}
	if(dem_e>1){
	dem_e=1;	
	}
	if(dem_r>1){
	dem_r=1;	
	}
	if(dem_l>1){
	dem_l=1;	
	}
	if(dem_i>1){
	dem_i=1;	
	}
	if(dem_n>1){
    dem_n=1;	
	}
	if(dem_m+dem_e+dem_r+dem_l+dem_i+dem_n==6){
	HP+=2;	
	}
	else{
	continue;	
	}

	}
	if	(HP>maxhp){
	HP=maxhp;	
	}
}
if(masukien[i-1]==99){
if(snt==0||level<8){
rescue=0;
return;	
}
else{
level=10;	
}
}
if(HP>maxhp){
HP=maxhp;	
}	
if(i==m){
rescue=1;	
display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
return;
}
display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
}
 cout << "Function isn't implemented" << endl;

}

