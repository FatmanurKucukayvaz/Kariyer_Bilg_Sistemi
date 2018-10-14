#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define DOSYA_YOLU "kisiselbilgiler.txt"
#define DOSYA_YOLU1 "dil.txt"
#define DOSYA_YOLU2 "ehliyet.txt"
#define DOSYA_YOLU3 "okulbilgileri.txt"
#define DOSYA_YOLU4 "isbilgileri.txt"
#define DOSYA_YOLU5 "ekdosya.txt"
struct dil
{
    char lang[20];
    struct dil *sonraki;
};
struct ehliyet
{
    char ehliyet[10];
    struct ehliyet *sonraki;
};
struct okul
{
    char okul[100];
    char tur[100];
    char bolum[100];
    char baslangic[50];
    char bitis[50];
    char ortalama[20];
    struct okul *sonraki;
};
struct is
{
    char isyeriAdi[200];
    char isyeriAdresi[200];
    char pozisyon[200];
    float sure;
    struct is *sonraki;
};
struct agac_ol
{
    char ad[50];
    char soyad[50];
    char adres[200];
    char tel[15];
    char eposta[200];
    int dogum_t;
    struct dil *ilk_d;
    struct ehliyet *ilk_e;
    struct okul *ilk_o;
    struct is *ilk_i;
    struct agac_ol *sag;
    struct agac_ol *sol;
};

typedef struct agac_ol dugum;
typedef struct dil diller;
typedef struct ehliyet ehliyetler;                 //[2]
typedef struct okul okullar;
typedef struct is isler;
dugum *agac_kok;
dugum *coklu_agac;
dugum *elde;

void ekle(dugum**,dugum*);

void ekle(dugum **agac,dugum *item)              //[2]
{
    if(!(*agac)){
        *agac=item;
        return;
    }
    if(strcmp(item->ad,(*agac)->ad)<0)
        ekle(&(*agac)->sol,item);
    else if(strcmp(item->ad,(*agac)->ad)>0)
        ekle(&(*agac)->sag,item);
}
int elemann=0;
int eleman_say(dugum *kok)
{
    if(kok!=NULL){
        if(kok->sol!=NULL && kok->sag!=NULL){
            elemann++;

        }
        else
            elemann++;
        eleman_say(kok->sol);
        eleman_say(kok->sag);
    }
    return elemann;
}
void yazEkrana(dugum* kok)
{
    printf("AD: ");
    printf("%s\n",kok->ad);
    printf("SOYAD: ");
    printf("%s\n",kok->soyad);
    printf("ADRES: ");
    printf("%s\n",kok->adres);
    printf("TEL: ");
    printf("%s\n",kok->tel);
    printf("EPOSTA: ");
    printf("%s\n",kok->eposta);
    printf("DOGUM TARIHI: ");
    printf("%d\n",kok->dogum_t);
    printf("DILLER:\n");
    diller *d=kok->ilk_d;
    while(d!=NULL){
        printf("%s\n",d->lang);
        d=d->sonraki;
    }
    printf("EHLIYETLER:\n");
    ehliyetler *e=kok->ilk_e;
    while(e!=NULL){
        printf("%s\n",e->ehliyet);
        e=e->sonraki;
    }
    printf("OKULLAR:\n");
    okullar *o=kok->ilk_o;
    while(o!=NULL){
        printf("OKULUN ADI: ");
        printf("%s\n",o->okul);
        printf("TURU: ");
        printf("%s\n",o->tur);
        printf("BOLUM: ");
        printf("%s\n",o->bolum);
        printf("BASLANGIC TARIHI: ");
        printf("%s\n",o->baslangic);
        printf("BITIS TARIHI: ");
        printf("%s\n",o->bitis);
        printf("ORTALAMA: ");
        printf("%s\n",o->ortalama);
        o=o->sonraki;
    }
    printf("CALISTIGI IS YERLERI:\n");
    isler *a=kok->ilk_i;
    while(a!=NULL){
        printf("ISYERININ ADI: ");
        printf("%s\n",a->isyeriAdi);
        printf("ISYERININ ADRESI: ");
        printf("%s\n",a->isyeriAdresi);
        printf("POZISYON: ");
        printf("%s\n",a->pozisyon);
        printf("CALISTIGI SURE: ");
        printf("%f\n",a->sure);
        a=a->sonraki;
    }
}
void dosyaya_yaz(dugum *kok, char yazilacak[20])
{
    FILE *dosya=fopen(DOSYA_YOLU5,"a");
    fprintf(dosya,"%s",yazilacak);
    fputs("\n",dosya);
    fprintf(dosya,"%s",kok->ad);
    fputs("\n",dosya);
    fprintf(dosya,"%s",kok->soyad);
    fputs("\n",dosya);
    fprintf(dosya,"%s",kok->adres);
    fputs("\n",dosya);
    fprintf(dosya,"%s",kok->tel);
    fputs("\n",dosya);
    fprintf(dosya,"%s",kok->eposta);
    fputs("\n",dosya);
    fprintf(dosya,"%d",kok->dogum_t);
    fputs("\n",dosya);
    diller *d=kok->ilk_d;
    while(d!=NULL){
        fprintf(dosya,"%s",d->lang);
        fputs("\n",dosya);
        d=d->sonraki;
    }
    ehliyetler *e=kok->ilk_e;
    while(e!=NULL){
        fprintf(dosya,"%s",e->ehliyet);
        fputs("\n",dosya);
        e=e->sonraki;
    }
    okullar *o=kok->ilk_o;
    while(o!=NULL){
        fprintf(dosya,"%s",o->okul);
        fputs("\n",dosya);
        fprintf(dosya,"%s",o->tur);
        fputs("\n",dosya);
        fprintf(dosya,"%s",o->bolum);
        fputs("\n",dosya);
        fprintf(dosya,"%s",o->baslangic);
        fputs("\n",dosya);
        fprintf(dosya,"%s",o->bitis);
        fputs("\n",dosya);
        fprintf(dosya,"%s",o->ortalama);
        fputs("\n",dosya);
        o=o->sonraki;
    }
    isler *a=kok->ilk_i;
    while(a!=NULL){
        fprintf(dosya,"%s",a->isyeriAdi);
        fputs("\n",dosya);
        fprintf(dosya,"%s",a->isyeriAdresi);
        fputs("\n",dosya);
        fprintf(dosya,"%s",a->pozisyon);
        fputs("\n",dosya);
        fprintf(dosya,"%f",a->sure);
        fputs("\n",dosya);
        a=a->sonraki;
    }
    fputs("-\n",dosya);
    fclose(dosya);
}
void preorder(dugum* kok)
{
    if(kok!=NULL){
        yazEkrana(kok);
        printf("\n");
        preorder(kok->sol);
        preorder(kok->sag);
    }
}
int derinlik (dugum *kok)
{
    int derinlik1=0;
    int derinlik2=0;
    dugum *e;
    if(kok==NULL){
        return derinlik1;
    }
    else{
    for(e=kok;e!=NULL;e=e->sag){
        derinlik1++;
    }
    for(e=kok;e!=NULL;e=e->sol){
        derinlik2++;
    }
    if(derinlik1>derinlik2)
        return derinlik1;
    else if(derinlik1<derinlik2)
        return derinlik2;
    else
        return derinlik2;
    }
}
void dosya_ac_kapa()
{
    FILE *dosya=fopen(DOSYA_YOLU,"w");
    FILE *dosya1=fopen(DOSYA_YOLU1,"w");
    FILE *dosya2=fopen(DOSYA_YOLU2,"w");
    FILE *dosya3=fopen(DOSYA_YOLU3,"w");
    FILE *dosya4=fopen(DOSYA_YOLU4,"w");
    fclose(dosya);
    fclose(dosya1);
    fclose(dosya2);
    fclose(dosya3);
    fclose(dosya4);
}
void bilgi_sil(dugum *kok,char isim[50])                            //[1]
{
    dugum *silinmeyenler=(dugum*)malloc(sizeof(dugum));
    diller *d;
    ehliyetler *e;
    okullar *o;
    isler *i;
    char isaret='-';
    if(kok!=NULL){

        if(strcmp(kok->ad,isim)!=0){
            FILE *dosya=fopen(DOSYA_YOLU,"a");
            FILE *dosya1=fopen(DOSYA_YOLU1,"a");
            FILE *dosya2=fopen(DOSYA_YOLU2,"a");
            FILE *dosya3=fopen(DOSYA_YOLU3,"a");
            FILE *dosya4=fopen(DOSYA_YOLU4,"a");
            if(derinlik(kok)>0){
                fputs("\n",dosya);
                fputs("\n",dosya1);
                fputs("\n",dosya2);
                fputs("\n",dosya3);
                fputs("\n",dosya4);
            }
            strcpy(silinmeyenler->ad,kok->ad);
            strcpy(silinmeyenler->soyad,kok->soyad);
            strcpy(silinmeyenler->adres,kok->adres);
            strcpy(silinmeyenler->tel,kok->tel);
            strcpy(silinmeyenler->eposta,kok->eposta);
            silinmeyenler->dogum_t=kok->dogum_t;
            silinmeyenler->ilk_d=kok->ilk_d;
            silinmeyenler->ilk_e=kok->ilk_e;
            silinmeyenler->ilk_o=kok->ilk_o;
            silinmeyenler->ilk_i=kok->ilk_i;
            fprintf(dosya,"%s",silinmeyenler->ad);
            fputs("\n",dosya);
            fprintf(dosya,"%s",silinmeyenler->soyad);
            fputs("\n",dosya);
            fprintf(dosya,"%s",silinmeyenler->adres);
            fputs("\n",dosya);
            fprintf(dosya,"%s",silinmeyenler->tel);
            fputs("\n",dosya);
            fprintf(dosya,"%s",silinmeyenler->eposta);
            fputs("\n",dosya);
            fprintf(dosya,"%d",silinmeyenler->dogum_t);
            fputs("\n",dosya);
            fprintf(dosya,"%c",isaret);
            for(d=silinmeyenler->ilk_d;d!=NULL;d=d->sonraki){
                fprintf(dosya1,"%s",d->lang);
                fputs("\n",dosya1);
            }
            fprintf(dosya1,"%c",isaret);
            for(e=silinmeyenler->ilk_e;e!=NULL;e=e->sonraki){
                fprintf(dosya2,"%s",e->ehliyet);
                fputs("\n",dosya2);
            }
            fprintf(dosya2,"%c",isaret);
            for(o=silinmeyenler->ilk_o;o!=NULL;o=o->sonraki){
                fprintf(dosya3,"%s",o->okul);
                fputs("\n",dosya3);
                fprintf(dosya3,"%s",o->tur);
                fputs("\n",dosya3);
                fprintf(dosya3,"%s",o->bolum);
                fputs("\n",dosya3);
                fprintf(dosya3,"%s",o->baslangic);
                fputs("\n",dosya3);
                fprintf(dosya3,"%s",o->bitis);
                fputs("\n",dosya3);
                fprintf(dosya3,"%s",o->ortalama);
                fputs("\n",dosya3);
            }
            fprintf(dosya3,"%c",isaret);
            for(i=silinmeyenler->ilk_i;i!=NULL;i=i->sonraki){
                fprintf(dosya4,"%s",i->isyeriAdi);
                fputs("\n",dosya4);
                fprintf(dosya4,"%s",i->isyeriAdresi);
                fputs("\n",dosya4);
                fprintf(dosya4,"%s",i->pozisyon);
                fputs("\n",dosya4);
                fprintf(dosya4,"%f",i->sure);
                fputs("\n",dosya4);
            }
            fprintf(dosya4,"%c",isaret);
            fclose(dosya);
            fclose(dosya1);
            fclose(dosya2);
            fclose(dosya3);
            fclose(dosya4);

        }
        bilgi_sil(kok->sol,isim);
        bilgi_sil(kok->sag,isim);
    }
}
void kisiAra(dugum* kok, char aranan[50])
{
    if(kok!=NULL){
        if(strcmp(kok->ad,aranan)==0)
            yazEkrana(kok);
        else if(strcmp(kok->ad,aranan)>0){
            kok=kok->sol;
            kisiAra(kok,aranan);
        }

        else{
            kok=kok->sag;
            kisiAra(kok,aranan);
        }

    }
}
void kisiAra_d(dugum* kok, char aranan[50])
{
    char yazilacak[20]="ARANAN KISI:";
    if(kok!=NULL){
        if(strcmp(kok->ad,aranan)==0)
            dosyaya_yaz(kok,yazilacak);
        else if(strcmp(kok->ad,aranan)>0){
            kok=kok->sol;
            kisiAra_d(kok,aranan);
        }

        else{
            kok=kok->sag;
            kisiAra_d(kok,aranan);
        }

    }
}
void ingBilenler(dugum *kok)
{
    diller *e;
    if(kok!=NULL){
        for(e=kok->ilk_d;e!=NULL;e=e->sonraki){
            if(strcmp(e->lang,"Ingilizce")==0)
                yazEkrana(kok);
                printf("\n");
        }
        ingBilenler(kok->sol);
        ingBilenler(kok->sag);
    }
}
void nulleme(dugum **kok)
{
    *kok=NULL;
}
void ingBilenler_c(dugum *kok)
{
    diller *e;
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    if(kok!=NULL){
        for(e=kok->ilk_d;e!=NULL;e=e->sonraki){
            if(strcmp(e->lang,"Ingilizce")==0){
                eklenen=kok;
                eklenen->sol=eklenen->sag=NULL;
                ekle(&elde,eklenen);
            }
        }
        ingBilenler_c(kok->sol);
        ingBilenler_c(kok->sag);
    }
    coklu_agac=elde;

}
void ingBilenler_d(dugum *kok)
{
    char yazilacak[20]="INGILIZCE BILENLER:";
    diller *e;
    if(kok!=NULL){
        for(e=kok->ilk_d;e!=NULL;e=e->sonraki){
            if(strcmp(e->lang,"Ingilizce")==0)
               dosyaya_yaz(kok,yazilacak);
        }
        ingBilenler_d(kok->sol);
        ingBilenler_d(kok->sag);
    }
}
void dilsayisi(dugum *kok)
{
    diller *ds;
    int sayac=0;
    if(kok!=NULL){
        for(ds=kok->ilk_d;ds!=NULL;ds=ds->sonraki){
            sayac++;
        }
        if(sayac>1)
            yazEkrana(kok);
            printf("\n");
        dilsayisi(kok->sol);
        dilsayisi(kok->sag);
    }

}
void dilsayisi_c(dugum *kok)
{
    diller *ds;
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    int sayac=0;
    if(kok!=NULL){
        for(ds=kok->ilk_d;ds!=NULL;ds=ds->sonraki){
            sayac++;
        }
        if(sayac>1){
            eklenen=kok;
            eklenen->sag=eklenen->sol=NULL;
            ekle(&elde,eklenen);
        }
        dilsayisi_c(kok->sol);
        dilsayisi_c(kok->sag);

    }
    coklu_agac=elde;
}
void dilsayisi_d(dugum *kok)
{
    char yazilacak[20]="BIRCOK DIL BILEN:";
    diller *ds;
    int sayac=0;
    if(kok!=NULL){
        for(ds=kok->ilk_d;ds!=NULL;ds=ds->sonraki){
            sayac++;
        }
        if(sayac>1)
            dosyaya_yaz(kok,yazilacak);
        dilsayisi_d(kok->sol);
        dilsayisi_d(kok->sag);
    }

}
void lisans(dugum *kok)
{
    okullar *b;
    if(kok!=NULL){
        for(b=kok->ilk_o;b!=NULL;b=b->sonraki){
            if(strcmp(b->tur,"Lisans")==0 && strcmp(b->ortalama,"e")!=0)
                yazEkrana(kok);
                printf("\n");
        }
        lisans(kok->sol);
        lisans(kok->sag);
    }
}
void lisans_c(dugum *kok)
{
    okullar *b;
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    if(kok!=NULL){
        for(b=kok->ilk_o;b!=NULL;b=b->sonraki){
            if(strcmp(b->tur,"Lisans")==0 && strcmp(b->ortalama,"e")!=0){
                eklenen=kok;
                eklenen->sol=eklenen->sag=NULL;
                ekle(&elde,eklenen);
            }
        }
        lisans_c(kok->sol);
        lisans_c(kok->sag);

    }
    coklu_agac=elde;
}
void lisans_d(dugum *kok)
{
    char yazilacak[20]="LISANS MEZUNLARI:";
    okullar *b;
    if(kok!=NULL){
        for(b=kok->ilk_o;b!=NULL;b=b->sonraki){
            if(strcmp(b->tur,"Lisans")==0 && strcmp(b->ortalama,"e")!=0)
                dosyaya_yaz(kok,yazilacak);
        }
        lisans_d(kok->sol);
        lisans_d(kok->sag);
    }
}
void yas_h(dugum *kok,int yas)
{
    if(kok!=NULL){
        if((2016-kok->dogum_t)<=yas)
            yazEkrana(kok);
            printf("\n");
        yas_h(kok->sol,yas);
        yas_h(kok->sag,yas);
    }
}
void yas_h_c(dugum *kok, int yas)
{
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    if(kok!=NULL){
        if((2016-kok->dogum_t)<=yas){
            eklenen=kok;
            eklenen->sol=eklenen->sag=NULL;
            ekle(&elde,eklenen);
        }
        yas_h_c(kok->sol,yas);
        yas_h_c(kok->sag,yas);
    }
    coklu_agac=elde;
}
void yas_h_d(dugum *kok,int yas)
{
    char yazilacak[20]="YASA GORE LISTE:";
    if(kok!=NULL){
        if((2016-kok->dogum_t)<=yas)
            dosyaya_yaz(kok,yazilacak);
        yas_h_d(kok->sol,yas);
        yas_h_d(kok->sag,yas);
    }
}
void belirli_ehliyet(dugum *kok,char ehlyt[10])
{
    ehliyetler *eh;
    if(kok!=NULL){
        for(eh=kok->ilk_e;eh!=NULL;eh=eh->sonraki){
            if(strcmp(eh->ehliyet,ehlyt)==0)
                yazEkrana(kok);
                printf("\n");
        }
        belirli_ehliyet(kok->sol,ehlyt);
        belirli_ehliyet(kok->sag,ehlyt);
    }
}
void belirli_ehliyet_c(dugum *kok,char ehlyt[10])
{
    ehliyetler *eh;
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    if(kok!=NULL){
        for(eh=kok->ilk_e;eh!=NULL;eh=eh->sonraki){
            if(strcmp(eh->ehliyet,ehlyt)==0){
                eklenen=kok;
                eklenen->sol=eklenen->sag=NULL;
                ekle(&elde,eklenen);            }
        }
        belirli_ehliyet_c(kok->sol,ehlyt);
        belirli_ehliyet_c(kok->sag,ehlyt);
    }
    coklu_agac=elde;
}
void belirli_ehliyet_d(dugum *kok,char ehlyt[10])
{
    char yazilacak[20]="EHLIYET FILTRELEME:";
    ehliyetler *eh;
    if(kok!=NULL){
        for(eh=kok->ilk_e;eh!=NULL;eh=eh->sonraki){
            if(strcmp(eh->ehliyet,ehlyt)==0)
                dosyaya_yaz(kok,yazilacak);
        }
        belirli_ehliyet_d(kok->sol,ehlyt);
        belirli_ehliyet_d(kok->sag,ehlyt);
    }
}
void listele()
{
    FILE *doc=fopen(DOSYA_YOLU,"r");
    FILE *doc1=fopen(DOSYA_YOLU1,"r");
    FILE *doc2=fopen(DOSYA_YOLU2,"r");
    FILE *doc3=fopen(DOSYA_YOLU3,"r");
    FILE *doc4=fopen(DOSYA_YOLU4,"r");
    char isaret[2];
    int i;
    dugum *simdiki;
    agac_kok=NULL;

    while(!feof(doc)){
        simdiki=(dugum*)malloc(sizeof(dugum));
        diller *ilk_d=NULL;
        diller *son_d=NULL;
        ehliyetler *ilk_e=NULL;
        ehliyetler *son_e=NULL;
        okullar *ilk_o=NULL;
        okullar *son_o=NULL;
        isler *ilk_i=NULL;
        isler *son_i=NULL;
        simdiki->sol=simdiki->sag=NULL;
        fscanf(doc,"%s",simdiki->ad);
        fscanf(doc,"%s",simdiki->soyad);
        fscanf(doc,"%s",simdiki->adres);
        fscanf(doc,"%s",simdiki->tel);
        fscanf(doc,"%s",simdiki->eposta);
        fscanf(doc,"%d",&simdiki->dogum_t);
        fscanf(doc,"%s",isaret);

        for(i=0;i<10;i++){
           diller *yeni_d=(diller*)malloc(sizeof(diller));
           fscanf(doc1,"%s",yeni_d->lang);
           if(strcmp(yeni_d->lang,isaret)==0){
                free(yeni_d);
                break;
           }
           else{
           if(ilk_d==NULL){
              yeni_d->sonraki=NULL;
              ilk_d=son_d=yeni_d;
           }
           else{
              yeni_d->sonraki=NULL;
              son_d->sonraki=yeni_d;
              son_d=yeni_d;
           }
           }
    }
       for(i=0;i<10;i++){
           ehliyetler *yeni_e=(ehliyetler*)malloc(sizeof(ehliyetler));
           fscanf(doc2,"%s",yeni_e->ehliyet);
           if(strcmp(yeni_e->ehliyet,isaret)==0){
                free(yeni_e);
                break;
           }
           else{
           if(ilk_e==NULL){
              yeni_e->sonraki=NULL;
              ilk_e=son_e=yeni_e;
           }
           else{
              yeni_e->sonraki=NULL;
              son_e->sonraki=yeni_e;
              son_e=yeni_e;
           }
       }
       }
       for(i=0;i<10;i++){
        okullar *yeni_o=(okullar*)malloc(sizeof(okullar));
        fscanf(doc3,"%s",yeni_o->okul);
        if(strcmp(yeni_o->okul,isaret)==0){
            free(yeni_o);
            break;
        }
        fscanf(doc3,"%s",yeni_o->tur);
        fscanf(doc3,"%s",yeni_o->bolum);
        fscanf(doc3,"%s",yeni_o->baslangic);
        fscanf(doc3,"%s",yeni_o->bitis);
        fscanf(doc3,"%s",yeni_o->ortalama);
        if(ilk_o==NULL){
            yeni_o->sonraki=NULL;
            ilk_o=son_o=yeni_o;
        }
        else{
            yeni_o->sonraki=NULL;
            son_o->sonraki=yeni_o;
            son_o=yeni_o;
        }
       }
       for(i=0;i<10;i++){
            isler *yeni_i=(isler*)malloc(sizeof(isler));
            fscanf(doc4,"%s",yeni_i->isyeriAdi);
            if(strcmp(yeni_i->isyeriAdi,isaret)==0){
                free(yeni_i);
                break;
            }
            fscanf(doc4,"%s",yeni_i->isyeriAdresi);
            fscanf(doc4,"%s",yeni_i->pozisyon);
            fscanf(doc4,"%f",&yeni_i->sure);
            if(ilk_i==NULL){
                yeni_i->sonraki=NULL;
                ilk_i=son_i=yeni_i;
            }
            else{
                yeni_i->sonraki=NULL;
                son_i->sonraki=yeni_i;
                son_i=yeni_i;
            }
       }
       (simdiki->ilk_o)=(ilk_o);
       (simdiki->ilk_d)=(ilk_d);
       (simdiki->ilk_e)=(ilk_e);
       (simdiki->ilk_i)=(ilk_i);
        ekle(&agac_kok,simdiki);
    }

    fclose(doc);
    fclose(doc1);
    fclose(doc2);
    fclose(doc3);
    fclose(doc4);
}
void bilgi_yenile(dugum *kok,char isim[50])
{
    bilgi_sil(kok,isim);
    int dil_say;
    int ehliyet_say;
    int okul_say;
    int is_say;
    int j;
    char isaret='-';
        FILE *dosya=fopen(DOSYA_YOLU,"a");
        FILE *dosya1=fopen(DOSYA_YOLU1,"a");
        FILE *dosya2=fopen(DOSYA_YOLU2,"a");
        FILE *dosya3=fopen(DOSYA_YOLU3,"a");
        FILE *dosya4=fopen(DOSYA_YOLU4,"a");
        listele();
        if(derinlik(agac_kok)>0){
            fputs("\n",dosya);
            fputs("\n",dosya1);
            fputs("\n",dosya2);
            fputs("\n",dosya3);
            fputs("\n",dosya4);
        }
        printf("ad:");
        fflush(stdin);
        fgets(kok->ad,20,stdin);
        fprintf(dosya,"%s",kok->ad);
        printf("soyad:");
        fgets(kok->soyad,20,stdin);
        fprintf(dosya,"%s",kok->soyad);
        printf("adres:");
        fgets(kok->adres,50,stdin);
        fprintf(dosya,"%s",kok->adres);
        printf("telefon:");
        fgets(kok->tel,15,stdin);
        fprintf(dosya,"%s",kok->tel);
        printf("eposta:");
        fgets(kok->eposta,100,stdin);
        fprintf(dosya,"%s",kok->eposta);
        printf("dogum tarihi:");
        scanf("%d",&kok->dogum_t);
        fprintf(dosya,"%d",kok->dogum_t);
        fputs("\n",dosya);
        fprintf(dosya,"%c",isaret);
        printf("kac dil biliyorsunuz:");
        scanf("%d",&dil_say);
        char dill[20];
        for(j=0;j<dil_say;j++){
            printf("dil:");
            fflush(stdin);
            fgets(dill,20,stdin);
            fprintf(dosya1,"%s",dill);
        }
        fprintf(dosya1,"%c",isaret);
        printf("kac ehliyetiniz var:");
        scanf("%d",&ehliyet_say);
        char ehlyt[10];
        for(j=0;j<ehliyet_say;j++){
            printf("ehliyet:");
            fflush(stdin);
            fgets(ehlyt,10,stdin);
            fprintf(dosya2,"%s",ehlyt);
        }
        fprintf(dosya2,"%c",isaret);
        printf("kac okul okudunuz:");
        scanf("%d",&okul_say);
        char okull[100];
        char tur[100];
        char bolum[100];
        char bas[50];
        char bit[50];
        char ort[20];
        for(j=0;j<okul_say;j++){
            printf("Okul:");
            fflush(stdin);
            fgets(okull,100,stdin);
            fprintf(dosya3,"%s",okull);
            printf("Turu:");
            fgets(tur,100,stdin);
            fprintf(dosya3,"%s",tur);
            printf("Bolum:");
            fgets(bolum,100,stdin);
            fprintf(dosya3,"%s",bolum);
            printf("Baslangic Tarihi:");
            fgets(bas,50,stdin);
            fprintf(dosya3,"%s",bas);
            printf("Bitis Tarihi:");
            fgets(bit,50,stdin);
            fprintf(dosya3,"%s",bit);
            printf("Ortalama:");
            fgets(ort,20,stdin);
            fprintf(dosya3,"%s",ort);
        }
        fprintf(dosya3,"%c",isaret);
        printf("kac is deneyiminiz var:");
        scanf("%d",&is_say);
        char isadres[200];
        char isadi[200];
        char pozisyon[200];
        float yil;
        if(is_say==0){
            strcpy(isadi,"0");
            fprintf(dosya4,"%s",isadi);
            fputs("\n",dosya4);
            strcpy(isadres,"0");
            fprintf(dosya4,"%s",isadres);
            fputs("\n",dosya4);
            strcpy(pozisyon,"0");
            fprintf(dosya4,"%s",pozisyon);
            fputs("\n",dosya4);
            yil=0;
            fprintf(dosya4,"%f",yil);
            fputs("\n",dosya4);

        }
        for(j=0;j<is_say;j=j++){
            printf("Isyeri Adi:");
            fflush(stdin);
            fgets(isadi,200,stdin);
            fprintf(dosya4,"%s",isadi);
            fputs("\n",dosya4);
            printf("Isyeri Adresi:");
            fgets(isadres,200,stdin);
            fprintf(dosya4,"%s",isadres);
            fputs("\n",dosya4);
            printf("Isyerindeki pozisyan/goreviniz:");
            fgets(pozisyon,200,stdin);
            fprintf(dosya4,"%s",pozisyon);
            fputs("\n",dosya4);
            printf("Kac yil calistiniz:");
            scanf("%f",&yil);
            fprintf(dosya4,"%f",yil);
            fputs("\n",dosya4);
        }
        fprintf(dosya4,"%c",isaret);
        fclose(dosya);
        fclose(dosya1);
        fclose(dosya2);
        fclose(dosya3);
        fclose(dosya4);
    }


void deneyim_suresi(dugum *kok, float deneyim_s)
{
    isler *den;
    if(kok!=NULL){
        den=kok->ilk_i;
        if(den->sure==deneyim_s)
            yazEkrana(kok);
            printf("\n");
        deneyim_suresi(kok->sol,deneyim_s);
        deneyim_suresi(kok->sag,deneyim_s);
    }
}
void deneyim_suresi_c(dugum *kok, float deneyim_s)
{
    isler *den;
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    if(kok!=NULL){
        den=kok->ilk_i;
        if(den->sure==deneyim_s){
            eklenen=kok;
            eklenen->sag=eklenen->sol=NULL;
            ekle(&elde,eklenen);
        }
        deneyim_suresi_c(kok->sol,deneyim_s);
        deneyim_suresi_c(kok->sag,deneyim_s);
    }
    coklu_agac=elde;
}
void deneyim_suresi_d(dugum *kok, float deneyim_s)
{
    isler *den;
    char yazilacak[20]="DENEYIMLILER:";
    if(kok!=NULL){
        den=kok->ilk_i;
        if(den->sure==deneyim_s)
            dosyaya_yaz(kok,yazilacak);
        deneyim_suresi_d(kok->sol,deneyim_s);
        deneyim_suresi_d(kok->sag,deneyim_s);
    }
}
void deneyimsiz(dugum *kok)
{
    isler *den;
    if(kok!=NULL){
        den=kok->ilk_i;
        if(den->sure==0)
            yazEkrana(kok);
            printf("\n");
        deneyimsiz(kok->sol);
        deneyimsiz(kok->sag);
    }
}
void deneyimsiz_c(dugum *kok)
{
    isler *den;
    dugum *eklenen=(dugum*)malloc(sizeof(dugum));
    eklenen=NULL;
    if(kok!=NULL){
        den=kok->ilk_i;
        if(den->sure==0){
            eklenen=kok;
            eklenen->sol=eklenen->sag=NULL;
            ekle(&elde,eklenen);
        }
        deneyimsiz_c(kok->sol);
        deneyimsiz_c(kok->sag);
    }
    coklu_agac=elde;
}
void deneyimsiz_d(dugum *kok)
{
    isler *den;
    char yazilacak[20]="DENEYIMSIZLER:";
    if(kok!=NULL){
        den=kok->ilk_i;
        if(den->sure==0)
            dosyaya_yaz(kok,yazilacak);
        deneyimsiz_d(kok->sol);
        deneyimsiz_d(kok->sag);
    }
}
int main()
{
    int i;
    char ad[50];
    char soyad[50];
    char adres[200];
    char tel[15];
    char eposta[200];
    int dogum_t;
    char dil[20];
    int dil_tane;
    char ehliyet[10];
    int ehliyet_say;
    char okul[100];
    char tur[100];
    char bolum[100];
    char baslangic[50];
    char bitis[50];
    char ortalama[20];
    int okul_say;
    char ehl[10];
    char aranan[50];
    char isyeriAdi[200];
    char isyeriAdresi[200];
    char pozisyon[200];
    float sure;
    int is_say;
    float deneyim;
    char isim[50];
    char isaret[2]="-";
    int secim=1000;
    int secim1=1000;
    int sifre;
    int yas;
    int tercih;
    printf("YONETICI SIFRESINI GIRIN:\n");
    printf("KAYIT ISLEMLERI ICIN 0'A BASIN:");
    scanf("%d",&sifre);
    if(sifre==1111){
    while(secim!=0){
            printf("KAYITLARI KISI SAYISINI AGAC DERINLIGINI GORMEK ICIN 1'E BASINIZ:\n");
            printf("BIRDEN FAZLA DIL BILENLERI LISTELEMEK ICIN 2'E BASIN:\n");
            printf("INGILIZCE BILENLER ICIN 3'YE BASINIZ:\n");
            printf("BELIRLI EHLIYET TIPI OLANLARI GORMEK ICIN 4'E BASINIZ:\n");
            printf("ARAMA YAPMAK ICIN 5'E BASINIZ:\n");
            printf("LISANS MEZUNU KISILERI GORMEK ICIN 6'YA BASINIZ:\n");
            printf("YAS HESABI ICIN 7'YE BASIN:\n");
            printf("DENEYIM FILTRELEME ICIN 8'E BASIN:\n");
            printf("DENEYIMSIZ KISILERI GORMEK ICIN 9'A BASIN:\n");
            printf("COKLU FILTRELEME ICIN 10'A BASIN:\n");
            printf("CIKMAK ICIN 0'A BASIN:");
            scanf("%d",&secim);
            switch(secim)
            {
            case 1:
                {
                    listele();
                    preorder(agac_kok);
                    printf("AGACIN ELEMAN SAYISI: %d\n",eleman_say(agac_kok));
                    printf("AGACIN DERINLIGI: %d\n",derinlik(agac_kok));
                    break;
                }
            case 2:
                {
                    listele();
                    dilsayisi(agac_kok);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        dilsayisi_d(agac_kok);
                    }
                    break;
                }
             case 3:
                 {
                    listele();
                    ingBilenler(agac_kok);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        ingBilenler_d(agac_kok);
                    }
                    break;
                 }
             case 4:
                 {
                    listele();
                    printf("bir ehliyet tipi girin:");
                    scanf("%s",ehl);
                    printf("\nBELIRLI EHLIYET\n\n");
                    belirli_ehliyet(agac_kok,ehl);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        belirli_ehliyet_d(agac_kok,ehl);
                    }
                    break;
                 }
             case 5:
                 {
                    listele();
                    printf("kisi adini girin:");
                    scanf("%s",aranan);
                    printf("\nARANAN KISI:\n\n");
                    kisiAra(agac_kok,aranan);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        kisiAra_d(agac_kok,aranan);
                    }
                    break;
                 }
             case 6:
                 {
                    listele();
                    lisans(agac_kok);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        lisans_d(agac_kok);
                    }
                    break;
                 }
             case 7:
                 {
                    listele();
                    printf("yas girin:");
                    scanf("%d",&yas);
                    printf("\nYAS HESABI:\n\n");
                    yas_h(agac_kok,yas);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        yas_h_d(agac_kok,yas);
                    }
                    break;
                 }
             case 8:
                {
                    listele();
                    printf("istediginiz deneyim suresini girin:");
                    scanf("%f",&deneyim);
                    deneyim_suresi(agac_kok,deneyim);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        deneyim_suresi_d(agac_kok,deneyim);
                    }
                    break;
                }
             case 9:
                {
                    listele();
                    printf("\nDENEYIMSIZ KISILER\n\n");
                    deneyimsiz(agac_kok);
                    printf("filtrelemeyi dosyaya yazdirmak icin 1'e basin:\n");
                    printf("istemiyorsaniz herhangi bir tusa basin:");
                    scanf("%d",&tercih);
                    if(tercih==1){
                        deneyimsiz_d(agac_kok);
                    }
                    break;
                }
             case 10:
                {
                    listele();
                    coklu_agac=NULL;
                    coklu_agac=agac_kok;
                    while(tercih!=0){
                        printf("Ingilizce icin:1 Birden fazla dil bilenler icin:2\n");
                        printf("Lisans mezunu olanlar icin:3 Yas filtreleme icin:4\n");
                        printf("Ehliyet filtreleme icin:5 Deneyim Filtreleme icin:6\n");
                        printf("Deneyimsizler icin:7 Cikis icin:0: ");
                        scanf("%d",&tercih);
                        if(tercih==1){
                            nulleme(&elde);
                            ingBilenler_c(coklu_agac);
                        }
                        if(tercih==2){
                            nulleme(&elde);
                            dilsayisi_c(coklu_agac);
                        }
                        if(tercih==3){
                            nulleme(&elde);
                            lisans_c(coklu_agac);
                        }
                        if(tercih==4){
                            nulleme(&elde);
                            printf("Bir yas girin:");
                            scanf("%d",&yas);
                            yas_h_c(coklu_agac,yas);
                        }
                        if(tercih==5){
                            printf("Bir ehliyet girin:");
                            scanf("%s",ehl);
                            nulleme(&elde);
                            belirli_ehliyet_c(coklu_agac,ehl);
                        }
                        if(tercih==6){
                            printf("Bir deneyin suresi girin:");
                            scanf("%f",&deneyim);
                            nulleme(&elde);
                            deneyim_suresi_c(coklu_agac,deneyim);
                        }
                        if(tercih==7){
                            nulleme(&elde);
                            deneyimsiz_c(coklu_agac);
                        }
                        if(tercih==0){
                            preorder(coklu_agac);
                            break;
                        }
                    }
                    break;
                }
             default:
                 break;

            }
    }
    }
    else{
        while(secim1!=0){
        printf("KAYIT ICIN 1'E BASINIZ:\n");
        printf("BILGI GORUNTULEME ICIN 2'YE BASINIZ:\n");
        printf("SISTEMDEN CIKMAK ICIN 3'E BASINIZ:\n");
        printf("BILGILERINIZI GUNCELLEMEK ICIN 4'E BASINIZ:\n");
        printf("PROGRAMDAN CIKMAK ICIN 0'A BASINIZ:");
        scanf("%d",&secim1);
        switch(secim1)
            {
             case 1:
                {
                    FILE *dosya;
                    dosya=fopen(DOSYA_YOLU,"a");
                    FILE *dosya1;
                    dosya1=fopen(DOSYA_YOLU1,"a");
                    FILE *dosya2;
                    dosya2=fopen(DOSYA_YOLU2,"a");
                    FILE *dosya3;
                    dosya3=fopen(DOSYA_YOLU3,"a");
                    FILE *dosya4=fopen(DOSYA_YOLU4,"a");
                    listele();
                    if(derinlik(agac_kok)>0){
                        fputs("\n",dosya);
                        fputs("\n",dosya1);
                        fputs("\n",dosya2);
                        fputs("\n",dosya3);
                        fputs("\n",dosya4);
                    }
                        printf("Adiniz:");
                        fflush(stdin);
                        fgets(ad,50,stdin);
                        printf("Soyadiniz:");
                        fgets(soyad,50,stdin);
                        printf("Adres:");
                        fgets(adres,200,stdin);
                        printf("Telefon:");
                        fgets(tel,15,stdin);
                        printf("Epostaniz:");
                        fgets(eposta,200,stdin);
                        printf("Dogum tarihiniz:");
                        scanf("%d",&dogum_t);
                        fprintf(dosya,"%s",ad);
                        fprintf(dosya,"%s",soyad);
                        fprintf(dosya,"%s",adres);
                        fprintf(dosya,"%s",tel);
                        fprintf(dosya,"%s",eposta);
                        fprintf(dosya,"%d",dogum_t);
                        fputs("\n",dosya);
                        fprintf(dosya,"%s",isaret);
                        printf("kac dil biliyorsunuz: ");
                        scanf("%d",&dil_tane);
                        if(dil_tane==0){
                            strcpy(dil,"0");
                            fprintf(dosya1,"%s",dil);
                            fputs("\n",dosya1);
                        }
                        for(i=0;i<dil_tane;i++){
                            printf("%d. dil:",i+1);
                            scanf("%s",dil);
                            fprintf(dosya1,"%s",dil);
                            fputs("\n",dosya1);
                        }
                        fprintf(dosya1,"%s",isaret);

                        printf("Kac ehliyetiniz var:");
                        scanf("%d",&ehliyet_say);
                        if(dil_tane==0){
                            strcpy(ehliyet,"0");
                            fprintf(dosya2,"%s",ehliyet);
                            fputs("\n",dosya2);
                        }
                        for(i=0;i<ehliyet_say;i++){
                            printf("%d. ehliyeti girin:",i+1);
                            scanf("%s",ehliyet);
                            fprintf(dosya2,"%s",ehliyet);
                            fputs("\n",dosya2);
                        }
                        fprintf(dosya2,"%s",isaret);

                       printf("kac okuldan mezun oldunuz:");
                       scanf("%d",&okul_say);

                       for(i=0;i<okul_say;i++){
                            printf("%d. okul:",i+1);
                            fflush(stdin);
                            fgets(okul,100,stdin);
                            printf("Turu:");
                            fgets(tur,100,stdin);
                            printf("Bolumunuz:");
                            fgets(bolum,100,stdin);
                            printf("Baslangic tarihiniz:");
                            fgets(baslangic,50,stdin);
                            printf("bitis tarihi:");
                            fgets(bitis,50,stdin);
                            printf("Not ortalamaniz:");
                            fgets(ortalama,20,stdin);
                            fprintf(dosya3,"%s",okul);
                            fprintf(dosya3,"%s",tur);
                            fprintf(dosya3,"%s",bolum);
                            fprintf(dosya3,"%s",baslangic);
                            fprintf(dosya3,"%s",bitis);
                            fprintf(dosya3,"%s",ortalama);
                       }
                       fprintf(dosya3,"%s",isaret);

                       printf("Kac is deneyiminiz var:");
                       scanf("%d",&is_say);
                       if(is_say==0){
                            strcpy(isyeriAdi,"0");
                            strcpy(isyeriAdresi,"0");
                            strcpy(pozisyon,"0");
                            sure=0;
                            fprintf(dosya4,"%s",isyeriAdi);
                            fputs("\n",dosya4);
                            fprintf(dosya4,"%s",isyeriAdresi);
                            fputs("\n",dosya4);
                            fprintf(dosya4,"%s",pozisyon);
                            fputs("\n",dosya4);
                            fprintf(dosya4,"%f",sure);
                            fputs("\n",dosya4);
                            fprintf(dosya4,"%s",isaret);
                       }
                       else{
                           for(i=0;i<is_say;i++){
                               fflush(stdin);
                               printf("is yeri adi:");
                               fflush(stdin);
                               fgets(isyeriAdi,200,stdin);
                               printf("is yeri adresiniz:");
                               fflush(stdin);
                               fgets(isyeriAdresi,200,stdin);
                               printf("is yerindeki pozisyonunuz/goreviniz:");
                               fgets(pozisyon,200,stdin);
                               printf("calistiginiz sure:");
                               scanf("%f",&sure);
                               fprintf(dosya4,"%s",isyeriAdi);
                               fprintf(dosya4,"%s",isyeriAdresi);
                               fprintf(dosya4,"%s",pozisyon);
                               fprintf(dosya4,"%f",sure);
                               fputs("\n",dosya4);
                           }
                           fprintf(dosya4,"%s",isaret);
                       }
                   fclose(dosya);
                   fclose(dosya1);
                   fclose(dosya2);
                   fclose(dosya3);
                   fclose(dosya4);
                   break;
                }
             case 2:
                {
                    listele();
                    printf("aranacak kisi:");
                    scanf("%s",aranan);
                    kisiAra(agac_kok,aranan);
                    break;
                }
             case 3:
                {
                    listele();
                    printf("silinecek kisi:");
                    scanf("%s",isim);
                    dosya_ac_kapa();
                    bilgi_sil(agac_kok,isim);
                    break;
                }
             case 4:
                {
                    listele();
                    printf("adiniz:");
                    scanf("%s",isim);
                    dosya_ac_kapa();
                    bilgi_yenile(agac_kok,isim);
                }
                }
        }
    }
    return 0;
}
