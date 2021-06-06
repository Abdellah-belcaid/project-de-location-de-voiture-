#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
typedef struct Voiture
{
 int idVoiture;
 char marque[15];
 char nomVoiture[15];
 char couleur[7];
 int nbplaces;
 int prixJour;
 int EnLocation;
} voiture;
typedef struct{
	int annee;
	int mois;
	int jour;
}date;
typedef struct
{
 float numContrat;
 int idVoiture;
 int idClient;
 date debut;
 date fin;
 int cout;
} contrat;
 typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int cin;
 char adresse[15];
 int telephone;
}client;

//MODIFIER voiture
void modifier_voitures()
{ voiture a;
   int id,k;
	FILE * fichier=fopen("voiture.txt","r");
	FILE * fichier2=fopen("exit.txt","a+");
	printf("saisir un id que vs voulez modifier");
	scanf("%d",&id);
   while (!feof(fichier))
   {

      	fscanf(fichier,"%6d %6s %6s %6s %7d %8d %9d\n",&a.idVoiture,a.marque,a.nomVoiture,a.couleur,&a.nbplaces,&a.prixJour,&a.EnLocation);


      	if(id==a.idVoiture)
		  {
			printf(",saisir 1 SI VOUS VOULEZ modifier la marque \n,2 pour le nom de voiture \n,3 pour la couleur \n,4 pour le nbr de places  \n,5pour le prix \n ");
			scanf("%d",&k);
			if(k==1)
			{
			printf("saisir la marque");
			scanf("%s",a.marque);
			}
				if(k==2)
				{
					printf("saisir le noveau nom");
					scanf("%s",a.nomVoiture);
				}
				if(k==3)
				{
					printf("saisir le noveau couleur");
						scanf("%s",a.couleur);
				}
			if(k==4)
			{	printf("saisir le nbr de places");
				scanf("%d",&a.nbplaces);
			}
				if(k==5)
				{printf("saisir le noveau prix");
					scanf("%d",&a.prixJour);
				}

			fprintf(fichier2,"%6d %6s %6s %6s %7d %8d %9d\n",a.idVoiture,a.marque,a.nomVoiture,a.couleur,a.nbplaces,a.prixJour,a.EnLocation);

		}
			 else
			 fprintf(fichier2,"%6d %6s %6s %6s %7d %8d %9d\n",a.idVoiture,a.marque,a.nomVoiture,a.couleur,a.nbplaces,a.prixJour,a.EnLocation);
	}
			fclose(fichier2);
			fclose(fichier);

			remove("voiture.txt");
			rename("exit.txt","voiture.txt");
}
//supprimer voiture
void supprimer_voiture()
{ voiture a;
    int id;
	FILE * fichier=fopen("voiture.txt","r");
	FILE * fichier2=fopen("exit.txt","a+");
	printf("saisir un id  DE VOITURE que vs voulez supprimer");
	scanf("%d",&id);
	do
	{

    	fscanf(fichier,"%6d %6s %6s %6s %7d %8d %9d\n",&a.idVoiture,a.marque,a.nomVoiture,a.couleur,&a.nbplaces,&a.prixJour,&a.EnLocation);
   		if(id!=a.idVoiture)
		   {

			fprintf(fichier2,"%6d %6s %6s %6s %7d %8d %9d\n",a.idVoiture,a.marque,a.nomVoiture,a.couleur,a.nbplaces,a.prixJour,a.EnLocation);
           }
   }while ( !feof(fichier) );
	fclose(fichier2);
	fclose(fichier);
	remove("voiture.txt");
	rename("exit.txt","voiture.txt");
}
//AJOUTER voiture
void ajouter_voiture(FILE * fichier)
{    voiture p;
		int n,i;
		fichier = fopen("voiture.txt", "a");
	printf("saisir le nbr des voitures ajouter");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("$$$$$$$$$$$$$la voiture numero %d\n",i+1);
		printf("donnez un id du voiture:\n");
		scanf("%d",&p.idVoiture);
		printf("donnez la marque du voiture:\n");
		scanf("%s",p.marque);
		printf("donnez le nom du voiture:\n");
		scanf("%s",p.nomVoiture);
		printf("donnez la couleur du voiture:\n");
		scanf("%s",p.couleur);
		printf("donnez nbr des places du voiture:\n");
		scanf("%d",&p.nbplaces);
		printf("donnez le prix pour louer la voiture durant un jour:\n");
		scanf("%d",&p.prixJour);
		printf("est ce que cette voiture a deja louee(si oui saisir 1 si non saisir 0)? \n");
		scanf("%d",&p.EnLocation);
		fprintf(fichier,"%6d %6s %6s %6s %7d %8d %9d\n",p.idVoiture,p.marque,p.nomVoiture,p.couleur,p.nbplaces,p.prixJour,p.EnLocation);
		fprintf(fichier,"\n");
	}
	 fclose(fichier);
}
//*************************************************LISTE fes voitures******************************************
void liste_des_voitures(FILE *fichier)
{ int i;
  char t[1000];
  printf("||id.V||mrq||nom.voi||cleur||nbr.place||prix.jr||location||\n");
  fichier = fopen("voiture.txt", "r");

  while(fgets(t,1000,fichier)!=NULL)
 {
	printf("%s\n",t);
 }
  fclose(fichier);
}
//ajouter client
void ajouter_client()
{ int i,n;
client a;
FILE *fichier=fopen("CLIENT.txt","a+");
printf("saisir le nbr des clients que vous venez d ajouter ");
scanf("%d",&n);
 for(i=0;i<n;i++)
 {


    printf("le client num %d\n",i+1);
    printf("--------------le id du client: ");
	scanf("%d",&a.idClient);
	printf("--------------le nom: ");
	scanf("%s",a.nom);
	printf("--------------le prenom: ");
	scanf("%s",a.prenom);
	printf("--------------cin: ");
	scanf("%d",&a.cin);
	printf("--------------adresse ");
	scanf("%s",a.adresse);
	printf("--------------tele: ");
	scanf("%d",&a.telephone);

 		 fprintf(fichier,"%6d %6s %6s %6d %6s %6d\n",a.idClient,a.nom,a.prenom,a.cin,a.adresse,a.telephone);
 		 //fprintf(fichier,"\n");

 }
 fclose(fichier);
}
//**************************************************************supprimer clients***************************************************
void supprimer_client()
{ client a;
int id;
	FILE * fichier=fopen("CLIENT.txt","r");
	FILE * fichier2=fopen("clear.txt","a+");
	printf("saisir un id que vs voulez supprimer");
	scanf("%d",&id);
	 do{

       		fscanf(fichier,"%6d %6s %6s %6d %6s %6d\n",&a.idClient,a.nom,a.prenom,&a.cin,a.adresse,&a.telephone);
			if(id!=a.idClient)
				{

				fprintf(fichier2,"%6d %6s %6s %6d %6s %6d\n",a.idClient,a.nom,a.prenom,a.cin,a.adresse,a.telephone);
  				}
	   }
  	while ( !feof(fichier) );
	fclose(fichier2);
	fclose(fichier);
	remove("CLIENT.txt");
	rename("clear.txt","CLIENT.txt");
}
//*********************************************************liste des clients***********************************************************
void liste_des_clients()
{ int i;
char t[1000];
 printf("||id.C||nom||prenom||CIN||ADRESSE||TELE||\n");
FILE *fichier = fopen("CLIENT.txt", "r");
while(fgets(t,1000,fichier)!=NULL)
{
	printf("%s\n",t);
}
  fclose(fichier);}
//*************************************modifier_client**********************************************************
void modifier_client()
{
	client a;
	int id,k;
	FILE * fichier=fopen("CLIENT.txt","r");
	FILE * fichier2=fopen("AVVVV.txt","a+");
	printf("saisir un id que vs voulez modifier");
	scanf("%d",&id);
while ( !feof(fichier) )
{

	fscanf(fichier,"%6d %6s %6s %6d %6s %6d\n",&a.idClient,a.nom,a.prenom,&a.cin,a.adresse,&a.telephone);


	if(id==a.idClient)
	{
		printf(",saisir 1 SI VOUS VOULEZ modifier le nom\n,2 pour le prenom\n,3 pour la cin\n,4 pour l adresse\n,5 pour le telephone\n ");
		scanf("%d",&k);

		if(k==1)
		{
			printf("saisir la noveau nom");
			scanf("%s",a.nom);
		}
		if(k==2)
		{
			printf("saisir le noveau prenom");
			scanf("%s",a.prenom);
		}
		if(k==3)
		{
 			printf("saisir le noveau cin");
			scanf("%d",&a.cin);
		}
		if(k==4)
		{
			printf("saisir le noveau adresse");
			scanf("%s",a.adresse);
		}
		if(k==5)
		{
			printf("saisir le noveau tele");
			scanf("%d",&a.telephone);
		}

	fprintf(fichier2,"%6d %6s %6s %6d %6s %6d\n",a.idClient,a.nom,a.prenom,a.cin,a.adresse,a.telephone);

	}
	else
	fprintf(fichier2,"%6d %6s %6s %6d %6s %6d\n",a.idClient,a.nom,a.prenom,a.cin,a.adresse,a.telephone);
}
	fclose(fichier2);
	fclose(fichier);
	remove("CLIENT.txt");
	rename("AVVVV.txt","CLIENT.txt");
}
//************************************** LOUER VOITURE*********************************************************
void info_client(int cin)
{ client a;
	FILE * fichier=fopen("CLIENT.txt","r");
	fscanf(fichier,"%6d %6s %6s %6d %6s %6d\n",&a.idClient,a.nom,a.prenom,&a.cin,a.adresse,&a.telephone);
	if(cin!=a.cin)
		{
			printf("vous devez saisir votre informations\n");
			ajouter_client();
		}

	else
	{
		printf("ce client deja existe dans la liste\n");
	}
	fclose(fichier);


}
void contrat_client()
    { contrat p;
    	FILE *fichier=fopen("contrat.txt","w");
     printf("saisir le contrat");
	    printf("*************************************************************************\n");
    printf("----------------        numero de contrat:");
    scanf("%f",&p.numContrat);
    printf("----------------        id du voiture: ");
    scanf("%d",&p.idVoiture);
    printf("----------------    id du client:");
    scanf("%d",&p.idClient);
    printf("----------------    date debut(annee/mois/jour):");
    scanf("%d %d %d",&p.debut.annee,&p.debut.mois,&p.debut.jour);
    printf("----------------   date fin(annee/mois/jour):");
    scanf("%d%d%d",&p.fin.annee,&p.fin.mois,&p.fin.jour);

    printf("----------------   cout:");
    scanf("%d",&p.cout);
    printf("*************************************************************************\n");
	fprintf(fichier,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",p.numContrat,p.idVoiture,p.idClient,p.debut.annee,p.debut.mois,p.debut.jour,p.fin.annee,p.fin.mois,p.fin.jour,p.cout);
	  if(p.debut.annee>p.fin.annee || p.debut.mois>p.fin.mois || p.debut.jour>p.fin.jour || p.debut.mois<1 || p.debut.mois>12 || p.debut.jour<1 || p.debut.jour>12 || p.debut.jour>p.fin.jour || p.fin.mois<1 || p.fin.mois>12 || p.fin.jour<1 || p.fin.jour>12 )
    {
    	    printf("la date n est pas valide veuillez resaisir le contrat\n");
 		   contrat_client();
	}
	fclose(fichier);
}
void louer_voiture()
{   FILE * fichier;
    int   m=0;
	contrat p;
	voiture b;
	client a;
	int id,cin;
    printf("*********\n");
    printf("saisir un id de voiture:");
    scanf("%d",&id);
    printf("saisir votre cin:");
    scanf("%d",&cin);
    printf("*********\n");
          fichier=fopen("voiture.txt","r");
          FILE * f2=fopen("loooo.txt","a+");
     while (!feof(fichier))
	 {


            fscanf(fichier,"%6d %6s %6s %6s %7d %8d %9d\n",&b.idVoiture,b.marque,b.nomVoiture,b.couleur,&b.nbplaces,&b.prixJour,&b.EnLocation);
           if( b.idVoiture==id)
		   {
                      m=1;
                      	if(b.EnLocation==1)
						  {
	         				  printf("la voiture n est pas disponible,voir la liste des voitures disponible en cliquant sur 1\n");
            				   	gestionvoiture();
                          }
                        if(b.EnLocation==0)
                         b.EnLocation=1;


		  }


    	 fprintf(f2,"%6d %6s %6s %6s %7d %8d %9d\n",b.idVoiture,b.marque,b.nomVoiture,b.couleur,b.nbplaces,b.prixJour,b.EnLocation);

      }
      	fclose(f2);
      	fclose(fichier);
      	remove("voiture.txt");
       rename("loooo.txt","voiture.txt");

  if(m==0)
   {

 	 printf("la voiture n existe pas\n");
 	 MenuPrincipal();
  }

  else
  {
 	info_client( cin);
 	contrat_client();
	MenuPrincipal();

  }

 fclose(fichier);
}
//************************************************modifier_contrat**********************************************************
void modifier_contrat()
{	contrat p;
	int num,k;
	FILE * fichier=fopen("contrat.txt","r");
	FILE * fichier2=fopen("supprim.txt","a+");
	printf("saisir le num de contrat que vous voulez modifier");
	scanf("%d",&num);
while ( !feof(fichier) )
{

	fscanf(fichier,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",&p.numContrat,&p.idVoiture,&p.idClient,&p.debut.annee,&p.debut.mois,&p.debut.jour,&p.fin.annee,&p.fin.mois,&p.fin.jour,&p.cout);


	if(num==p.numContrat)
	{
		printf(",saisir 1 SI VOUS VOULEZ modifier la date de debut\n,2 pour la date de fin\n,3 pour le cout\n");
		scanf("%d",&k);

	if(k==1)
	{
		printf("saisir le noveau date de debut:(%d/%d/%d)\n",p.debut.annee,p.debut.mois,p.debut.jour);
		scanf("%d %d %d",&p.debut.annee,&p.debut.mois,&p.debut.jour);
	}
	if(k==2)
	{
		printf("saisir le noveau date de fin:(%d/%d/%d)\n",p.fin.annee,p.fin.mois,p.fin.jour);
		scanf("%d %d %d",&p.fin.annee,&p.fin.mois,&p.fin.jour);
	}
		if(k==3)
	{
		printf("saisir le noveau cout:");
		scanf("%d",&p.cout);
	}
	fprintf(fichier2,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",p.numContrat,p.idVoiture,p.idClient,p.debut.annee,p.debut.mois,p.debut.jour,p.fin.annee,p.fin.mois,p.fin.jour,p.cout);

	}
	else
	fprintf(fichier2,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",p.numContrat,p.idVoiture,p.idClient,p.debut.annee,p.debut.mois,p.debut.jour,p.fin.annee,p.fin.mois,p.fin.jour,p.cout);
}
	fclose(fichier2);
	fclose(fichier);
	remove("contrat.txt");
	rename("supprim.txt","contrat.txt");
}
//************************************************** visualiser_contrat******************************************************
void visualiser_contrat()

{
	int num,n=0;
	FILE *fichier;
	contrat p;
  printf("saisir le numero de contrat voulez vous afficher:");
  scanf("%d",&num);
  printf("||NUM.C||ID.V||ID.C||DATE.DEBUT(AN/MOI/JR)||DATE.FIN(AN/MOI/JR)||COUT||\n");
	fichier=fopen("contrat.txt","r");
		if (fichier != NULL)
		{
		do{
			fscanf(fichier,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",&p.numContrat,&p.idVoiture,&p.idClient,&p.debut.annee,&p.debut.mois,&p.debut.jour,&p.fin.annee,&p.fin.mois,&p.fin.jour,&p.cout);
		if(num==p.numContrat)
		{

			n=1;
			printf("%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",p.numContrat,p.idVoiture,p.idClient,p.debut.annee,p.debut.mois,p.debut.jour,p.fin.annee,p.fin.mois,p.fin.jour,p.cout);
        }
	  	}while (!feof(fichier));
       }

	fclose(fichier);
      	if(n==0)
      	printf("\n\t\t\tle contrat n exeste pas");
}
//*************************************************************retourner_voiture***********************************************************
void modifiII_enlocation(int id)
{
	 voiture a;
	FILE * fichier=fopen("voiture.txt","r");
	FILE * fichier2=fopen("PRO.txt","a+");
while (!feof(fichier))
{

		fscanf(fichier,"%6d %6s %6s %6s %7d %8d %9d\n",&a.idVoiture,a.marque,a.nomVoiture,a.couleur,&a.nbplaces,&a.prixJour,&a.EnLocation);
		if( a.idVoiture==id)
		a.EnLocation=0;
		fprintf(fichier2,"%6d %6s %6s %6s %7d %8d %9d\n",a.idVoiture,a.marque,a.nomVoiture,a.couleur,a.nbplaces,a.prixJour,a.EnLocation);
}
	fclose(fichier2);
	fclose(fichier);
	remove("voiture.txt");
	rename("PRO.txt","voiture.txt");
}
void supprimer_contrat(int id)
{
	 contrat p;
	FILE * fichier=fopen("contrat.txt","r");
	FILE * fichier2=fopen("windows.txt","a+");
	do{

		fscanf(fichier,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",&p.numContrat,&p.idVoiture,&p.idClient,&p.debut.annee,&p.debut.mois,&p.debut.jour,&p.fin.annee,&p.fin.mois,&p.fin.jour,&p.cout);
		if(id!=p.idVoiture)
		{
			fprintf(fichier2,"%8f  %7d  %7d  %4d  %2d  %2d  %4d  %2d  %2d  %10d\n",p.numContrat,p.idVoiture,p.idClient,p.debut.annee,p.debut.mois,p.debut.jour,p.fin.annee,p.fin.mois,p.fin.jour,p.cout);
		}
	 }while ( !feof(fichier) );
	fclose(fichier2);
	fclose(fichier);
	remove("contrat.txt");
	rename("windows.txt","contrat.txt");
}
void retourner_voiture()
{int id;
	printf("saisir le id de voiture que vous voulez retourner");
	scanf("%d",&id);
	modifiII_enlocation(id);
	supprimer_contrat(id);
}
//******************************************************************************************************************
int location()
{  FILE * fichier;
    int choix;

	printf("\n                                                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                \xb3 Location voiture\xb3");
	printf("\n                                                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n                                                                  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xba    Visualiser contrat....................1   \xba");
	printf("\n                                                                  \xba    Louer  voiture........................2   \xba");
	printf("\n                                                                  \xba    Returner voiture......................3   \xba");
	printf("\n                                                                  \xba    Modifier contrat......................4   \xba");
	printf("\n                                                                  \xba    Retour................................5   \xba");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                                                                Votre choix  :  ");

    scanf("%d",&choix);

     switch(choix)
   {
    case 1:visualiser_contrat();
 	 location();
  	  break;
  case 2: louer_voiture();
  location();

	break;
    case 3:retourner_voiture();
   location();
   	break;

  case 4:modifier_contrat();
  location();

   break;
    case 5: MenuPrincipal();

   break;
}
}
//**************************************************************************************************
int gestionvoiture()
{   FILE *fichier;

    int choix;
    int n;

    voiture t[100];


	printf("\n                                                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                \xb3 Gestion voiture \xb3");
	printf("\n                                                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n                                                                  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xba    Visualiser voiture....................1   \xba");
	printf("\n                                                                  \xba    Ajouter voiture.......................2   \xba");
	printf("\n                                                                  \xba    Modifier voiture......................3   \xba");
	printf("\n                                                                  \xba    Supprimer voiture.....................4   \xba");
	printf("\n                                                                  \xba    Retour................................5   \xba");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                                                                Votre choix  :  ");
            scanf("%d",&choix);
    scanf("%d",&choix);
    switch(choix)
   {
    case 1:liste_des_voitures(fichier);
 	 gestionvoiture();
  	  break;
   case 2: ajouter_voiture(fichier);
   gestionvoiture();
	break;
    case 3:modifier_voitures( fichier);
   gestionvoiture();
   	break;
  case 4:supprimer_voiture();
  gestionvoiture();
   break;
   case 5:MenuPrincipal();
   break;
}
}
int gestionclients()
{FILE * fichier;
    int choix,n;

	 printf("\n                                                                                \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                \xb3 Gestion client  \xb3");
	printf("\n                                                                                \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n                                                                  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xba    Visualiser client.....................1   \xba");
	printf("\n                                                                  \xba    ajouter  client.......................2   \xba");
	printf("\n                                                                  \xba    Modifier  client......................3   \xba");
	printf("\n                                                                  \xba    Supprimer client......................4   \xba");
	printf("\n                                                                  \xba    Retour................................5   \xba");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                                                                Votre choix  :  ");

     switch(choix)
    {
    case 1:
	liste_des_clients();
     gestionclients();
    break;
    case 2:ajouter_client();
    gestionclients();
    break;
    case 3:modifier_client();
     gestionclients();
    break;
    case 4: supprimer_client();
    gestionclients();
	break;
	case 5:MenuPrincipal();
}
}
//******************************************************************************************
int MenuPrincipal()
{
    int choix;



	printf("\n                                                                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                 \xb3 Menu Principale \xb3");
	printf("\n                                                                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n                                                                  \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xba    Location..............................1   \xba");
	printf("\n                                                                  \xba    Gestion voitures......................2   \xba");
	printf("\n                                                                  \xba    Gestion clients.......................3   \xba");
	printf("\n                                                                  \xba    Quitter...............................4   \xba");
	printf("\n                                                                  \xba                                              \xba");
	printf("\n                                                                  \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

  printf("                                                                                votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:location();
    break;
    case 2:gestionvoiture();
    break;
    case 3:gestionclients();

    break;

}
}
//*************************************************************************
int main()
{

	printf("\n              \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n              \xb3    BY : abdellah belcaid - SMI4                                                              \xb3");
	printf("\n              \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	MenuPrincipal();

	return 0;
}












