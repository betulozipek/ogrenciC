 #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
FILE *dosya;
struct ogrenci{
  char ad[21];
    char soyad[21];
    char mail[30];
    int no;
    int telno;
 };
struct ogrenci kisi[10];
void ekle(void); 
void bul(void);
void liste(void);



int main(){
do{ 

system("cls");
enbasadon:
printf("\t\tMENU \n1- Kayit ekle\n2- Kayit bul \n3- sirala \n4- Cikis \n\nLutfen islemi seciniz:");

switch(getch()){
 case '1':
 system("cls");
 ekle();
 goto enbasadon;
  break;
  
 
 case '2':
 system("cls");
 
   bul();
  break;
  
  
 
case '3':
 system("cls");
 
   liste();
  break;
 
 

 case '4':
    exit(1);
  break;
 
 
 
 default:
  printf("Hatali Giris");
 goto enbasadon;
 
}
}while(1);
 getch();
 return 0;
}

void ekle(void){
int i =0;
 int karakterSayisi;
 dosya=fopen("sinif.txt","a+");
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nOgrenci Bilgilerini Girin: ");
 do{ 
  i++;
  fflush(stdin);
  do
  {
 printf(" Ogrencinin Adi : ");
  
  gets(kisi[i].ad);
   karakterSayisi=strlen(kisi[i].ad); 
            if(karakterSayisi>20)
            {
                printf("\nOgrenci Adi 20 Karakterden Fazla Olamaz!\n");
                printf("Lutfen Ogrenci Adini Tekrar Giriniz.\n\n");
            }
        
 }        while(karakterSayisi>20);
  
  do{
  printf(" Ogrencinin soyad : ");
  gets(kisi[i].soyad);
  karakterSayisi=strlen(kisi[i].soyad); 
            if(karakterSayisi>20)
            {
                printf("\nOgrenci soyadý 20 Karakterden Fazla Olamaz!\n");
                printf("Lutfen Ogrenci soyadý Tekrar Giriniz.\n\n");
            }
        
   }      while(karakterSayisi>20);
   
   printf(" Ogrencinin mail : ");
  gets(kisi[i].mail);

  printf(" Ogrenci Numarasi : ");

  
scanf("%d",&kisi[i].no);

 

  printf(" Ogrencinin tel no : ");
  scanf("%d",&kisi[i].telno);
  

  

   
   fprintf(dosya,"%10s %10s %10s %10d %10d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,kisi[i].no,kisi[i].telno);
  puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);

 fclose(dosya);
 puts("\nBilgiler kaydedildi ");
 
}


void bul(void)

{

int durum=0;
		int secim = 0;
	 char mail [30];

int n = (sizeof(kisi) / sizeof(int));		
enbasadon:
	printf("\n\n\n\n\n1. Tel no ile bul '\n");
	printf("\n\n\n2. Ogrenci no ile bul \n");
	printf("\n\n\n3.Mail\n");
		printf("\n\n\n4.Ust menu\n");
	printf("\n\n\nLutfen seciminizi yapiniz:", secim);
	scanf("%d", &secim);
	system("cls");

	switch (secim) {
	case 1:
		printf("\nTel no ile bul -\n");
 int telno;
int i;

 fflush(stdin);
 printf("\nOgrenci tel giriniz: ");
 scanf("%d",&telno);
 dosya=fopen("sinif.txt","r");
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){
  for(i=0;i<=n;i++){
  
   fscanf(dosya,"%s %s %s %d %d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,&kisi[i].no,&kisi[i].telno); 
   if(telno==kisi[i].telno){ 
  printf("%10s %10s %10s %10d %10d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,kisi[i].no,kisi[i].telno);
    durum=1;
   }}
  }
  fclose(dosya);
  if(durum == 0){ 
   puts("Kayit bulunamadi devam etmek icin bir tusa basiniz...");
  }
      
               
		goto enbasadon;
		break;
		system("cls");
   
   case 2:
   	printf("\n-Ogrenci no ile bul-\n");
               int no;

 fflush(stdin);
 printf("\nOgrenci ogrenci no giriniz: ");

 scanf("%d",&no);
 dosya=fopen("sinif.txt","r");
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){
  for(i=0;i<=n;i++){
  
   fscanf(dosya,"%s %s %s %d %d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,&kisi[i].no,&kisi[i].telno); 
   if(no==kisi[i].no){ 
   printf("%10s %10s %10s %10d %10d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,kisi[i].no,kisi[i].telno);
    durum=1;
   }}
  }
  fclose(dosya);
  if(durum == 0){ 
   puts("Kayit bulunamadi devam etmek icin bir tusa basiniz...");
  }
 
             
		goto enbasadon;
		break;
		system("cls");
	
	
	case 3:
		printf("\n-mail ile bul-\n");
                printf("----------------\n\n");
                char mail[20];

 fflush(stdin);
 printf("\nOgrenci mail giriniz: ");
 gets(mail);
 dosya=fopen("sinif.txt","r");
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){
  for(i=0;i<=n;i++){
  
   fscanf(dosya,"%s %s %s %d %d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,&kisi[i].no,&kisi[i].telno); 
   if(strcmp(kisi[i].mail,mail) == 0){ 
   printf("%10s %10s %10s %10d %10d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,kisi[i].no,kisi[i].telno);
    durum=1;
   }}
  
  
  if(durum == 0)
   puts("Kayit bulunamadi ");
  } 
      fclose(dosya);  
	        
		goto enbasadon;
  
 break;
		
		

		system("cls");
		
		
	case 4:
	
	 break;
	 
	 default:
		printf("hatali");
		goto enbasadon;
		break;



	}
}





void liste(void){ 
// ilk kez çaðrýldýðýnda düzgün çalýþýyor ama tekrar çaðýlýnca hatalý sýralýyor nedenini çözemedim 
int n = (sizeof(kisi) / sizeof(int));	
		int secim = 0;
	 char ad [30];
enbasadon:
		

	printf("\n\n\n\n\n1.Isme göre listele '\n");
	printf("\n\n\n2. Ogrenci no ile listele\n");
	printf("\n\n\n3.Ust menu\n");
		
	printf("\n\n\nLutfen seciminizi yapiniz:", secim);
	scanf("%d", &secim);
	system("cls");

	switch (secim) {
		
		
	case 1:
		
		
{
	struct ogrenci gec;
	printf("\nisme göre-\n");
	
int i;

	
	 dosya=fopen("sinif.txt","r");
	 
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){
 
   for(i=0;i<=10;i++){

 fscanf(dosya,"%s %s %s %d %d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,&kisi[i].no,&kisi[i].telno);
for(i=0;i<=10;i++){
    if (strcmp(kisi[i].ad, kisi[i+1].ad) > 0)
    {strcpy(gec.ad,kisi[i+1].ad);
    strcpy(gec.soyad,kisi[i+1].soyad);
     strcpy(gec.mail,kisi[i+1].mail);
	 gec.no=kisi[i+1].no;
	 gec.telno=kisi[i+1].telno;
	 strcpy(kisi[i+1].ad,kisi[i].ad);
	 strcpy(kisi[i+1].soyad,kisi[i].soyad);
	 strcpy(kisi[i+1].mail,kisi[i].mail);
	 kisi[i+1].no=kisi[i].no;
	 kisi[i+1].telno=kisi[i].telno;
	 strcpy(kisi[i].ad,gec.ad);
	 strcpy(kisi[i].soyad,gec.soyad);
	 strcpy(kisi[i].mail,gec.mail);
	 kisi[i].no=gec.no;
	 kisi[i].telno=gec.telno;
                
            }
   
	}

}
 
   }
  		
				   
fclose(dosya);
for(i=0;i<=11;i++)
 
printf("%10s\t %10s\t %10s\t %10d\t %10d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,kisi[i].no,kisi[i].telno);
  
 
	
	goto enbasadon;	
		break;
		
		system("cls");
		
}







  case 2:
  	


  	{
  		
struct ogrenci gec;

int i;
	
	 dosya=fopen("sinif.txt","r");
	 
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
 printf("OGRENCI NO ILE SIRALAMA \n\n");
  while(!feof(dosya)){
 
   for(i=0;i<=10;i++){

 fscanf(dosya,"%s %s %s %d %d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,&kisi[i].no,&kisi[i].telno);
   for(i=0;i<=10;i++){
   if(kisi[i].no>kisi[i+1].no )
   {strcpy(gec.ad,kisi[i+1].ad);
    strcpy(gec.soyad,kisi[i+1].soyad);
     strcpy(gec.mail,kisi[i+1].mail);
	 gec.no=kisi[i+1].no;
	 gec.telno=kisi[i+1].telno;
	 strcpy(kisi[i+1].ad,kisi[i].ad);
	 strcpy(kisi[i+1].soyad,kisi[i].soyad);
	 strcpy(kisi[i+1].mail,kisi[i].mail);
	 kisi[i+1].no=kisi[i].no;
	 kisi[i+1].telno=kisi[i].telno;
	 strcpy(kisi[i].ad,gec.ad);
	 strcpy(kisi[i].soyad,gec.soyad);
	 strcpy(kisi[i].mail,gec.mail);
	 kisi[i].no=gec.no;
	 kisi[i].telno=gec.telno;
   }
} 
}
	}


 fclose(dosya);
  	for(i=0;i<=11;i++)
	
 printf("%10s %10s %10s %10d %10d\n",kisi[i].ad,kisi[i].soyad,kisi[i].mail,kisi[i].no,kisi[i].telno);
     


 
 goto enbasadon;
 break;
system("cls");
}

case 3 : 
	


break;


default:
 printf("hatalý giris");
 goto enbasadon;
 break;
 
 }
 
  }

