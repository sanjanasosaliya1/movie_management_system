
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n_of_record=0;

//structures
struct actor
{
    char name[20];
    int age;
    int no_of_movie;
};
struct actress
{
    char name[20];
    int age;
    int no_of_movie;
};
struct hit_song
{
    char name[20];
    char singer[20];
};
struct director
{
    char name[20];
    int no_of_movies;
};
struct releasedate
{
    int date;
    int month;
    int year;
};
struct movies
{
   int no;
   char name[20];
   char type[20];
   int collection;
   int budget;
   int rating;
   struct actor ar;
   struct actress as;
   struct hit_song h_s;
   struct releasedate r_d;
   struct director dr;
}mv;

//functions 
void menu();
void insert();
void display();
void delete();
void update();
void collection_sort();
void search();
void search_by_as();
void verdict();
void search_by_type();

//main function
int main()
{
    int ch1,ch2=0;

 do
    {
    menu();

    printf("\n Enter your choice=");
    scanf("%d",&ch1);

    switch(ch1)
    {
    case 1:
    {
        insert();
    }
        break;

    case 2:
    {
      display();
    }
        break;

    case 3:
    {
       delete();
    }
        break;

    case 4:
    {
        update();
    }
        break;

    case 5:
    {
       collection_sort();
    }
        break;

    case 6:
    {
        search();
    }
        break;

    case 7:
    {
        search_by_as();
    }
        break;

    case 8:
    {
        verdict();
    }
        break;

    case 9:
    {
        search_by_type();
    }
        break;

    case 10:
    {
       printf("\n exit");
       exit(0);
    }
        break;

    default:
    {
        printf("\n Invalid value");
    }
        break;

    }
      printf("\n Do you wish to continue then Enter 0=");
      scanf("%d",&ch2);
    }
    while (ch2==0);

    return 0;
}

// for loop
int get_nor()
{
    FILE *fp;
    fp = fopen("movie.txt", "w");
    n_of_record = 0;
    while (fread(&mv, sizeof(mv), 1, fp))
    {
        n_of_record = n_of_record + 1;
    }
    fclose(fp);

    return n_of_record;
}

// for checking available number
int avl_no(int n)
{
	FILE *fp;
	int c=0;
	fp=fopen("movie.txt","r");
	while(!feof(fp))
	{
		fread(&mv,sizeof(mv),1,fp);
		if(n==mv.no)
		{
			fclose(fp);
			return 1;
		}
	}
	return 0;
}

//for sorting
int how_no()
{
  int i=0;
  FILE *fp;
  fp=fopen("movie.txt","r");
  while(fread(&mv,sizeof(struct movies),1,fp))
  {
    i++;
  }
  fclose(fp);
  return i;
}

// insert data
void insert()
{
    FILE *fp;
    fp=fopen("movie.txt","a");

        printf("\n Enter the number=");
        scanf("%d",&mv.no);

        printf("\n Enter the movie name=");
        scanf("%s",mv.name);

        printf("\n Enter the movie type=");
        scanf("%s",mv.type);

        printf("\n Enter the actor name=");
        scanf("%s",mv.ar.name);

        printf("\n Enter the age of actor=");
        scanf("%d",&mv.ar.age);

        printf("\n Enter the no of movies in which actor works=");
        scanf("%d",&mv.ar.no_of_movie);

        printf("\n Enter the actress name=");
        scanf("%s",mv.as.name);

        printf("\n Enter the age of actress=");
        scanf("%d",&mv.as.age);

        printf("\n Enter the no of movies in which actress works=");
        scanf("%d",&mv.as.no_of_movie);

        printf("\n Enter the hit song=");
        scanf("%s",mv.h_s.name);

        printf("\n Enter the singer name=");
        scanf("%s",mv.h_s.singer);

        printf("\n Enter the collection of the movie=");
        scanf("%d",&mv.collection);

        printf("\n Enter the budget of the movie=");
        scanf("%d",&mv.budget);

        printf("\n Enter the release date=");
        scanf("%d",&mv.r_d.date);

        printf("\n Enter the release month=");
        scanf("%d",&mv.r_d.month);

        printf("\n Enter the release year=");
        scanf("%d",&mv.r_d.year);

        printf("\n Enter the director name=");
        scanf("%s",mv.dr.name);

        printf("\n Enter the no of movies in which director works=");
        scanf("%d",&mv.dr.no_of_movies);

        printf("\n Enter the rating=");
        scanf("%d",&mv.rating);

    fwrite(&mv,sizeof(mv),1,fp);
    fclose(fp);
}

// menu
void menu()
{
    printf("\n________________Menu_______________\n");

    printf("\n 1.Insert data about movie");
    printf("\n 2.Display all the information");
    printf("\n 3.Delete the record");
    printf("\n 4.Update the data");
    printf("\n 5.Collection wise sorting");
    printf("\n 6.Search movies by the director name");
    printf("\n 7.Search by actor and actress");
    printf("\n 8.Verdict of the movies");
    printf("\n 9.Search by type");
    printf("\n 10.Exit");
}

// show the details
void display()
{
    FILE *fp;
    fp=fopen("movie.txt","r");

        printf("\n_______________ABOUT THE MOVIE________________");
        printf("\n");
        printf("\nNumber\tMovie_name\tType\t\tActor_name\tActress_name\tHit_song\tCollection(cr)\tBudget(cr)\tReleaseyear\tDirector_name\tRating");
        while(fread(&mv,sizeof(mv),1,fp))
        {
            printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
        }
        fclose(fp);
    printf("\n");

    fp=fopen("movie.txt","r");
        printf("\n_______________ABOUT THE ACTOR_______________");
        printf("\n");
        printf("\nNumber\tActor_name\t\tActor_age\t Movies_of_actor");
        while(fread(&mv,sizeof(mv),1,fp))
        {
            printf("\n%d\t%s\t\t %d\t\t %d",mv.no,mv.ar.name,mv.ar.age,mv.ar.no_of_movie);
        }
        fclose(fp);
    printf("\n");

    fp=fopen("movie.txt","r");
        printf("\n_______________ABOUT THE ACTRESS_______________");
        printf("\n");
        printf("\nNumber\t\tActress_name\t\tActress_age\tMovies_of_actress");
        while(fread(&mv,sizeof(mv),1,fp))
        {
            printf("\n%d\t\t%s\t\t %d\t\t %d",mv.no,mv.as.name,mv.as.age,mv.as.no_of_movie);
        }
        fclose(fp);
    printf("\n");

    fp=fopen("movie.txt","r");
        printf("\n_______________ABOUT THE SONG_______________");
        printf("\n");
        printf("\nNumber\tSong_name\tSinger_name");
        while(fread(&mv,sizeof(mv),1,fp))
        {
            printf("\n%d\t%s\t\t %s",mv.no,mv.h_s.name,mv.h_s.singer);
        }
        fclose(fp);
    printf("\n");

    fp=fopen("movie.txt","r");
        printf("\n_______________ABOUT THE RELISE_______________");
        printf("\n");
        printf("\nNumber\tRelise_date\tRelise_month\tRelise_year");
        while(fread(&mv,sizeof(mv),1,fp))
        {
            printf("\n%d\t%d\t\t %d\t\t %d",mv.no,mv.r_d.date,mv.r_d.month,mv.r_d.year);
        }
        fclose(fp);
    printf("\n");

    fp=fopen("movie.txt","r");
        printf("\n_______________ABOUT THE DIRECTOR_______________");
        printf("\n");
        printf("\nNumber\tDirector_name\t\tMovies_of_director");
        while(fread(&mv,sizeof(mv),1,fp))
        {
            printf("\n%d\t%s\t\t %d",mv.no,mv.dr.name,mv.dr.no_of_movies);
        }
        fclose(fp);
    printf("\n");
}

void collection_sort()
{
   FILE *fp;
   fp=fopen("movie.txt","r");
   int c=how_no();
   struct movies *p;
   p=(struct movies *)calloc(c,sizeof(struct movies));
   int i=0;
   while(fread(&mv,sizeof(struct movies),1,fp))
   {
    *(p+i)=mv;
    i++;
   }
   for(int i=0;i<c;i++)
   {
    for(int j=0;j<c;j++)
    {
        if((p+i)->collection>(p+j)->collection)
        {
            mv=*(p+i);
            *(p+i)=*(p+j);
            *(p+j)=mv;
        }
    }
   }
       printf("\nNumber\tMovie_name\tType\t\tActor_name\tActress_name\tHit_song\tCollection(cr)\tBudget(cr)\tReleaseyear\tDirector_name\tRating");
   for(i=0;i<c;i++)
   {
      printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",(p + i)->no,(p + i)->name,(p + i)->type,(p + i)->ar.name,(p + i)->as.name,(p + i)->h_s.name,(p + i)->collection,(p + i)->budget,(p + i)->r_d.year,(p + i)->dr.name,(p + i)->rating);
   }
   fclose(fp);
}

//delete option
void delete()
{
	FILE *fp;
	FILE *ptr;
	int temp,s;

	printf("\n Enter the number you want to delete=");
	scanf("%d",&temp);
	if(avl_no(temp)==0)
	{
		printf("\n Sorry! this name is not available");
	}
	else
	{
		fp=fopen("movie.txt","r");
		ptr=fopen("temp.txt","w");
		while(fread(&mv,sizeof(mv),1,fp))
		{
			s=mv.no;
			if(s!=temp)
			{
			    fwrite(&mv,sizeof(mv),1,ptr);
			}
		}
	
	fclose(fp);
	fclose(ptr);

	fp=fopen("movie.txt","w");
	ptr=fopen("temp.txt","r");
	while(fread(&mv,sizeof(mv),1,ptr))
	{
		fwrite(&mv,sizeof(mv),1,fp);
	}
	printf("\n record deleted");
	fclose(fp);
	fclose(ptr);
    }
}

// verdict of the movie
void verdict()
{
	FILE *fp;
    int ch=0,ch2=0;

		fp=fopen("movie.txt","r");
	    while(fread(&mv, sizeof(mv), 1, fp))
        {
    	do
				{
				printf("\n 1.flop movies");
				printf("\n 2.hit movies");
				printf("\n 3.superhit movies");
                printf("\n 4.blockbuster movies");

                printf("\n Enter choice:");
				scanf("%d",&ch);
				switch(ch)
				{
				    case 1:
                    {
                         fp=fopen("movie.txt","r");
	                    while(fread(&mv, sizeof(mv), 1, fp))
                        {
	   				         if(mv.collection<mv.budget)
                            {
                                printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
                            }
                        }
                        	fclose(fp);
                    }
                        break;

				    case 2:
                    {
                        fp=fopen("movie.txt","r");
	                    while(fread(&mv, sizeof(mv), 1, fp))
                        {
				            if(mv.collection>2*mv.budget && mv.collection<3*mv.budget)
                            {
                                 printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
                            }
                         }
                        	fclose(fp);
                    }
                        break;

                    case 3:
                    {
                        fp=fopen("movie.txt","r");
	                    while(fread(&mv, sizeof(mv), 1, fp))
                        {
                           if(mv.collection>3*mv.budget && mv.collection<4*mv.budget)
                            {
                                 printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
                            }
                         }
                        	fclose(fp);
                    }
                        break;

                    case 4:
                    {
                        fp=fopen("movie.txt","r");
	                    while(fread(&mv, sizeof(mv), 1, fp))
                        {
                            if(mv.collection>4*mv.budget)
                            {
                                printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
                            }
                        }
                        	fclose(fp);
                    }
                        break;

				    default:
                        {
				    	    printf("\n Invalid input");
                        }
				    	break;
				}
				printf("\n Enter 0 if you want to continue verdict menu=");
				scanf("%d",&ch2);
                }
				while(ch2==0);
	            fwrite(&mv,sizeof(mv),1,fp);
        }
	fclose(fp);
}

// search by movie name
void search()
{
    FILE *fp2;
    char name[20];
    int s=0, avl;
    printf("Enter the director name you search=");
    scanf("%s", name);

    fp2 = fopen("movie.txt", "r");
    while (fread(&mv, sizeof(mv), 1, fp2))
    {
        if(strcmp(name,mv.dr.name)==0)
        {
            printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
            s++;
        }
    }
    if(s==0)
    {
        printf("\n No record found with this name");
    }
    else
    {
        printf("\n %d record found",s);
    }
    fclose(fp2);
}

//search by actor and actress
void search_by_as()
{
    FILE *fp2;
    char a1[20],a2[20];
    int match=0;
    printf("\n Enter actor name=");
    scanf("%s",a1);
    printf("\n Enter actress name=");
    scanf("%s",a2);

    fp2=fopen("movie.txt","r");
    while(fread(&mv,sizeof(mv),1,fp2))
    {
        if(strcmp(a1,mv.ar.name)==0)
        {
            if(strcmp(a2,mv.as.name)==0)
            {
                printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
                match++;
            }
        }
    }
        
    if(match==0)
    {
        printf("\n No record found with this name");
    }
    else
    {
        printf("\n %d record found",match);
    }
    fclose(fp2);
}

// for update the data
void update()
{
    FILE *fp;
    FILE *ptr;
	int temp,s,ch=0,ch2=0;
	printf("\n Enter the number you want to update=");
	scanf("%d",&temp);

	if(avl_no(temp)==0)
	{
		printf("\n Sorry! this name is not available");
	}
	else
	{
		fp=fopen("movie.txt","r");
		ptr=fopen("temp.txt","w");
		while(fread(&mv,sizeof(mv),1,fp))
		{
			s=mv.no;
			if(s!=temp)
			{
			    fwrite(&mv,sizeof(mv),1,ptr);
			}
			else
			{
				do
				{
				    printf("\n 1.Update  singer name");
				    printf("\n 2.Update collection and rating");
                    printf("\n 3.Update no of movies of actors, actress and directors");

				    printf("\n Enter choice=");
				    scanf("%d",&ch);
				    switch(ch)
				    {
				        case 1:
                        {
                            printf("\n Enter singer name=");
					        scanf("%s",mv.h_s.singer);
                        }
                            break;

				        case 2:
				        {
                            printf("\n Enter new collection=");
				    	    scanf("%d",&mv.collection);

                            printf("\n Enter the new rating=");
                            scanf("%d",&mv.rating);
                        }
				    	    break;

                        case 3:
                        {
                            printf("\n Enter the no of movies of an actor=");
                            scanf("%d",&mv.ar.no_of_movie);

                            printf("\n Enter the no of movies of an actress=");
                            scanf("%d",&mv.as.no_of_movie);

                            printf("\n Enter the no of movies of an director=");
                            scanf("%d",&mv.dr.no_of_movies);
                        }
                            break;

				        default:
                        {
				    	    printf("\n Invalid input");
                        }
				    	    break;
				    }
				    printf("\n Enter 0 if you want to continue update menu=");
				    scanf("%d",&ch2);
			    }
				while(ch2==0);
				fwrite(&mv,sizeof(mv),1,ptr);
			}
		
	}
	fclose(fp);
	fclose(ptr);
	fp=fopen("movie.txt","w");
	ptr=fopen("temp.txt","r");
	while(fread(&mv,sizeof(mv),1,ptr))
	{
		fwrite(&mv,sizeof(mv),1,fp);
	}
	printf("\n record updated");
	fclose(fp);
	fclose(ptr);
    }
}

// search by type of movie
void search_by_type()
{
    FILE *fp2;
    char type[20];
    int s=0, avl;
    printf("Enter the type of movie which you want to search=");
    scanf("%s", type);

    fp2 = fopen("movie.txt", "r");
    while (fread(&mv, sizeof(mv), 1, fp2))
    {
        if(strcmp(type,mv.type)==0)
        {
            printf("\n%d\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%s\t%d",mv.no,mv.name,mv.type,mv.ar.name,mv.as.name,mv.h_s.name,mv.collection,mv.budget,mv.r_d.year,mv.dr.name,mv.rating);
            s++;
        }
    }
    if(s==0)
    {
        printf("\n No record found with this name");
    }
    else
    {
        printf("\n %d record found",s);
    }
    fclose(fp2);  
}
            