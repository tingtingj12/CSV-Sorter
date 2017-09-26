#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* color;
    char* director_name;
    int num_critic_for_reviews;
    time_t duration;
    int director_facebook_likes;
    int actor_3_facebook_likes;
    char* actor_2_name;
    int actor_1_facebook_likes;
    int gross;
    char* genres;
    char* actor_1_name;
    char* movie_title;
    int num_voted_users;
    int cast_total_facebook_likes;
    char* actor_3_name;
    int facenumber_in_poster;
    char* plot_keywords;
    char* movie_imdb_link;
    int num_user_for_reviews;
    char* language;
    char* country;
    char* content_rating;
    int budget;
    int title_year;
    int actor_2_facebook_likes;
    int imdb_score;
    int aspect_ratio;
    int movie_facebook_likes;
} Entry;

int main() {
    FILE *fPointer = fopen("test.txt", "r");

    /*
    char singleLine[150];
    while(!feof(fPointer)) {
        fgets(singleLine, 150, fPointer);
        puts(singleLine);
    }*/
    
    int entryCount;
    fscanf(fPointer, "%i", &entryCount);

    Entry *entries = malloc(sizeof(Entry) * entryCount);

    for (int i = 0; i < entryCount; i++) {
        int nameLen;
        fscanf(fPointer, "%i", &nameLen);

        entries[i].name = malloc(sizeof(char) * (nameLen + 1));
        fscanf(fPointer, "%s %i", entries[i].name, &entries[i].score);
        printf("%i. %s - %i\n", i + 1, entries[i].name, entries[i].score);
    }

    for (int i = 0; i < entryCount; i++) {
        free(entries[i].name);
    }

    fclose(fPointer);
    free(entries);
    return 0;
}
