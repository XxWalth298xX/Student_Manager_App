#include "students.h"
#include "add_student.h"
#include "Searching.h"
#include "list.h"
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

//bien to luu tru thong tin sinh vien
profile *person = NULL;
const char *selected_id;
//

//dinh nghia appdata de su sung trong cac ham button
typedef struct {
    GtkBuilder *builder;
    profile *students;
    long student_count; // Optional: if searching needs the array size
} AppData;
//

// cap nhat thong tin chi tiet
void update_detail_box(profile *p, GtkBuilder *builder) {
    printf("run1\n");

    //lay cac label tu builder cua glade
    GtkWidget *label_id = GTK_WIDGET(gtk_builder_get_object(builder, "label_id"));
    GtkWidget *label_name = GTK_WIDGET(gtk_builder_get_object(builder, "label_name"));
    GtkWidget *label_department = GTK_WIDGET(gtk_builder_get_object(builder, "label_department"));
    GtkWidget *label_birth = GTK_WIDGET(gtk_builder_get_object(builder, "label_birth"));
    GtkWidget *label_num = GTK_WIDGET(gtk_builder_get_object(builder, "label_num"));
    GtkWidget *label_nationality = GTK_WIDGET(gtk_builder_get_object(builder, "label_nationality"));
    GtkWidget *label_class = GTK_WIDGET(gtk_builder_get_object(builder, "label_class"));
    GtkWidget *label_score1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_score1"));
    GtkWidget *label_score2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_score2"));
    GtkWidget *label_score3 = GTK_WIDGET(gtk_builder_get_object(builder, "label_score3"));
    GtkWidget *label_aver = GTK_WIDGET(gtk_builder_get_object(builder, "label_aver"));
    //

    //kiem tra cac label da duoc tao ra hay chua
    if (!label_id || !label_name || !label_birth || !label_num || !label_nationality || !label_department ||
        !label_class || !label_score1 || !label_score2 || !label_score3 || !label_aver) {
        g_print("Error:labels not found in Glade file\n");
        return;
    }
    //

    //lay gia tri tu profile va chuyen doi thanh chuoi
    gchar score1[16], score2[16], score3[16], average[16];
    g_snprintf(score1, sizeof(score1), "%.2f", p->math);
    g_snprintf(score2, sizeof(score2), "%.2f", p->lit);
    g_snprintf(score3, sizeof(score3), "%.2f", p->eng);
    g_snprintf(average, sizeof(average), "%.2f", p->aver);

    gchar *id_text = g_strdup_printf("Mã số: %s", p->MSSV);
    if (selected_id) {
        g_free((gchar *)selected_id);
    }
    selected_id = g_strdup(p->MSSV);
    gchar *name_text = g_strdup_printf("Tên: %s", p->NAME);
    gchar *department_text = g_strdup_printf("Ngành: %s", p->department);
    gchar *birth_text = g_strdup_printf("Ngày sinh: %s", p->DATE);
    gchar *num_text = g_strdup_printf("SĐT: %s", p->NUM);
    gchar *nationality_text = g_strdup_printf("Địa chỉ: %s", p->ADD);
    gchar *class_text = g_strdup_printf("Lớp: %s", p->CLASS);
    gchar *score1_text = g_strdup_printf("Điểm Toán: %s", score1);
    gchar *score2_text = g_strdup_printf("Điểm Văn: %s", score2);
    gchar *score3_text = g_strdup_printf("Điểm Anh: %s", score3);
    gchar *aver_text = g_strdup_printf("Overall: %s", average);
    //

    //cap nhat cac label de in len detail box
    gtk_label_set_text(GTK_LABEL(label_id), id_text); 
    gtk_label_set_text(GTK_LABEL(label_name), name_text);
    gtk_label_set_text(GTK_LABEL(label_department), department_text);
    gtk_label_set_text(GTK_LABEL(label_birth), birth_text);
    gtk_label_set_text(GTK_LABEL(label_num), num_text);
    gtk_label_set_text(GTK_LABEL(label_nationality), nationality_text);
    gtk_label_set_text(GTK_LABEL(label_class), class_text);
    gtk_label_set_text(GTK_LABEL(label_score1), score1_text);
    gtk_label_set_text(GTK_LABEL(label_score2), score2_text);
    gtk_label_set_text(GTK_LABEL(label_score3), score3_text);
    gtk_label_set_text(GTK_LABEL(label_aver), aver_text);
    //

    //giai phong bien tam thoi
    g_free(id_text);
    g_free(name_text);
    g_free(department_text);
    g_free(birth_text);
    g_free(num_text);
    g_free(nationality_text);
    g_free(class_text);
    g_free(score1_text);
    g_free(score2_text);
    g_free(score3_text);
    g_free(aver_text);

    printf("selected_id:%s\n",selected_id);
    if (person) {
        g_free(person);
    }
}
//

// cap nhat thong tin chi tiet 1
void update_detail_box1(profile *p, GtkBuilder *builder) {
    printf("run1\n");

    //lay cac label tu builder cua glade
    GtkWidget *label_id = GTK_WIDGET(gtk_builder_get_object(builder, "label_id1"));
    GtkWidget *label_name = GTK_WIDGET(gtk_builder_get_object(builder, "label_name1"));
    GtkWidget *label_department = GTK_WIDGET(gtk_builder_get_object(builder, "label_department1"));
    GtkWidget *label_birth = GTK_WIDGET(gtk_builder_get_object(builder, "label_birth1"));
    GtkWidget *label_num = GTK_WIDGET(gtk_builder_get_object(builder, "label_num1"));
    GtkWidget *label_nationality = GTK_WIDGET(gtk_builder_get_object(builder, "label_nationality1"));
    GtkWidget *label_class = GTK_WIDGET(gtk_builder_get_object(builder, "label_class1"));
    GtkWidget *label_score1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_score4"));
    GtkWidget *label_score2 = GTK_WIDGET(gtk_builder_get_object(builder, "label_score5"));
    GtkWidget *label_score3 = GTK_WIDGET(gtk_builder_get_object(builder, "label_score6"));
    GtkWidget *label_aver = GTK_WIDGET(gtk_builder_get_object(builder, "label_aver1"));
    //

    //kiem tra cac label da duoc tao ra hay chua
    if (!label_id || !label_name || !label_birth || !label_num || !label_nationality || !label_department ||
        !label_class || !label_score1 || !label_score2 || !label_score3 || !label_aver) {
        g_print("Error:labels not found in Glade file\n");
        return;
    }
    //

    //lay gia tri tu profile va chuyen doi thanh chuoi
    gchar score1[16], score2[16], score3[16], average[16];
    g_snprintf(score1, sizeof(score1), "%.2f", p->math);
    g_snprintf(score2, sizeof(score2), "%.2f", p->lit);
    g_snprintf(score3, sizeof(score3), "%.2f", p->eng);
    g_snprintf(average, sizeof(average), "%.2f", p->aver);

    gchar *id_text = g_strdup_printf("Mã số: %s", p->MSSV);
    gchar *name_text = g_strdup_printf("Tên: %s", p->NAME);
    gchar *department_text = g_strdup_printf("Ngành: %s", p->department);
    gchar *birth_text = g_strdup_printf("Ngày sinh: %s", p->DATE);
    gchar *num_text = g_strdup_printf("SĐT: %s", p->NUM);
    gchar *nationality_text = g_strdup_printf("Địa chỉ: %s", p->ADD);
    gchar *class_text = g_strdup_printf("Lớp: %s", p->CLASS);
    gchar *score1_text = g_strdup_printf("Điểm Toán: %s", score1);
    gchar *score2_text = g_strdup_printf("Điểm Văn: %s", score2);
    gchar *score3_text = g_strdup_printf("Điểm Anh: %s", score3);
    gchar *aver_text = g_strdup_printf("Overall: %s", average);
    //

    //cap nhat cac label de in len detail box
    gtk_label_set_text(GTK_LABEL(label_id), id_text);
    gtk_label_set_text(GTK_LABEL(label_name), name_text);
    gtk_label_set_text(GTK_LABEL(label_department), department_text);
    gtk_label_set_text(GTK_LABEL(label_birth), birth_text);
    gtk_label_set_text(GTK_LABEL(label_num), num_text);
    gtk_label_set_text(GTK_LABEL(label_nationality), nationality_text);
    gtk_label_set_text(GTK_LABEL(label_class), class_text);
    gtk_label_set_text(GTK_LABEL(label_score1), score1_text);
    gtk_label_set_text(GTK_LABEL(label_score2), score2_text);
    gtk_label_set_text(GTK_LABEL(label_score3), score3_text);
    gtk_label_set_text(GTK_LABEL(label_aver), aver_text);
    //

    //giai phong bien tam thoi
    g_free(id_text);
    g_free(name_text);
    g_free(department_text);
    g_free(birth_text);
    g_free(num_text);
    g_free(nationality_text);
    g_free(class_text);
    g_free(score1_text);
    g_free(score2_text);
    g_free(score3_text);
    g_free(aver_text);

    if (person) {
        g_free(person);
    }
}
//

//khi nhan du lieu tu treeview
// ham nay se duoc goi khi click vao mot dong trong treeview
void on_row_activated(GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer user_data) {
    printf("run2\n");

    GtkBuilder *builder = (GtkBuilder *)user_data;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    GtkTreeIter iter;

    //kiem tra xem treeview nao duoc chon
    if (treeview == GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview1"))) {
        g_print("Row activated in treeview1\n");
    } else {
        g_print("Row activated in treeview\n");
    }

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gchar *id = NULL, *name = NULL, *nganh = NULL, *birth = NULL, *num = NULL;
        gchar *add = NULL, *class = NULL;
        float score1, score2, score3, aver;

        gtk_tree_model_get(model, &iter,
                           0, &id, 1, &name, 2, &nganh, 3, &birth, 4, &num,
                           5, &add, 6, &class,
                           7, &score1, 8, &score2, 9, &score3, 10, &aver,
                           -1);

        profile p;
        strcpy(p.MSSV, id);
        strcpy(p.NAME, name);
        strcpy(p.department, nganh);
        strcpy(p.DATE, birth);
        strcpy(p.NUM, num);
        strcpy(p.ADD, add);
        strcpy(p.CLASS, class);
        p.math = score1;
        p.lit = score2;
        p.eng = score3;
        p.aver = aver;

        if (treeview == GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview1"))) {
            update_detail_box1(&p, builder);
        } else {
            update_detail_box(&p, builder);
        }
    } else {
        g_print("Error: data not found NULL!\n");
    }
}
//

//ham nay se duoc goi khi hien thi thong tin tu stu
void populate_treeview(GtkTreeView *treeview, GList *list) {
    printf("run3\n");
    //
    GtkListStore *store = gtk_list_store_new(11,
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
        G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT
    );

    GtkTreeIter iter;
    for (GList *l = list; l != NULL; l = l->next) {
        profile *p = (profile *)l->data;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
            0, p->MSSV,
            1, p->NAME,
            2, p->department,
            3, p->DATE,
            4, p->NUM,
            5, p->ADD,
            6, p->CLASS,
            7, p->math,
            8, p->lit,
            9, p->eng,
            10, p->aver,
            -1
        );
    }
    gtk_tree_view_set_model(treeview, GTK_TREE_MODEL(store));
    g_object_unref(store);
}
//

//ham nay se duoc goi khi load thong tin tu file
GList *read_data_from_file(const char *filename) {
    printf("run4\n");
    GList *list = NULL;
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        g_printerr("File error: %s\n", filename);
        return NULL;
    }

    char line[256];
    int line_number = 0;

    while (fgets(line, sizeof(line), fp)) {
        line_number++;
        line[strcspn(line, "\n")] = 0;

        profile *p = g_malloc(sizeof(profile));
        if (!p) {
            g_printerr("Memory allocation failed at line %d\n", line_number);
            continue;
        }

        char *token = strtok(line, ",");
        if (!token) {
            g_printerr("Missing MSSV at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->MSSV, token, sizeof(p->MSSV) - 1);
        p->MSSV[sizeof(p->MSSV) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) {
            g_printerr("Missing NAME at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->NAME, token, sizeof(p->NAME) - 1);
        p->NAME[sizeof(p->NAME) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) {
            g_printerr("Missing DATE at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->department, token, sizeof(p->department) - 1);
        p->department[sizeof(p->department) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) {
            g_printerr("Missing department at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->DATE, token, sizeof(p->DATE) - 1);
        p->DATE[sizeof(p->DATE) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) {
            g_printerr("Missing NUM at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->NUM, token, sizeof(p->NUM) - 1);
        p->NUM[sizeof(p->NUM) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) {
            g_printerr("Missing ADD at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->ADD, token, sizeof(p->ADD) - 1);
        p->ADD[sizeof(p->ADD) - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) {
            g_printerr("Missing CLASS at line %d\n", line_number);
            g_free(p);
            continue;
        }
        strncpy(p->CLASS, token, sizeof(p->CLASS) - 1);
        p->CLASS[sizeof(p->CLASS) - 1] = '\0';

        float *scores[] = {&p->math, &p->lit, &p->eng, &p->aver};
        const char *score_names[] = {"math", "literature", "english", "average"};
        int i;

        for (i = 0; i < 4; i++) {
            token = strtok(NULL, ",");
            if (!token) {
                g_printerr("Missing %s at line %d\n", score_names[i], line_number);
                g_free(p);
                break;
            }

            char *endptr;
            double value = strtod(token, &endptr);
            if (endptr == token || *endptr != '\0') {
                g_printerr("Invalid %s '%s' at line %d\n", score_names[i], token, line_number);
                g_free(p);
                break;
            }

            if (i < 3 && (value < 0.0 || value > 10.0)) {
                g_printerr("%s score %.2f out of range at line %d\n", score_names[i], value, line_number);
                g_free(p);
                break;
            }

            *scores[i] = (float)value;
        }

        if (i < 4) {
            continue;
        }

        list = g_list_append(list, p);
    }

    fclose(fp);
    if (!list) {
        g_print("No valid data loaded from %s\n", filename);
    }
    return list;
}
//

//giai phong danh sach cac profile
void free_person_list(GList *list) {
    printf("run5\n");
    for (GList *l = list; l != NULL; l = l->next) {
        profile *p = l->data;
        g_free(p);  
    }
    g_list_free(list);
}
//

//ham nay se duoc goi khi nhan button nham load lai thong tin tu file
void reload_data(GtkTreeView *treeview, const char *filename) {
    GList *data = read_data_from_file(filename);
    if (!data) {
        g_printerr("Error: Failed to load data from file %s\n", filename);
    }

    populate_treeview(treeview, data);
    g_list_free_full(data, (GDestroyNotify)g_free);
}

void reload_data1(GtkTreeView *treeview, const char *filename) {
    GList *data = read_data_from_file(filename);
    if (!data) {
        g_printerr("Error: Failed to load data from file %s\n", filename);
    }

    populate_treeview(treeview, data);
    g_list_free_full(data, (GDestroyNotify)g_free);
}
//

//ham nay se duoc goi khi nhan button tim kiem
void on_search_button_clicked(GtkButton *button, gpointer user_data) {
    printf("run_search\n");
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *students = app_data->students;
    printf("%s",students[2006474].NAME);
    GtkTreeView *treeview = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview"));
    if (!treeview) {
        g_print("Error: Treeview widget not found\n");
        return;
    }

    GtkWidget *entry_name = GTK_WIDGET(gtk_builder_get_object(builder, "entry_name"));
    GtkWidget *entry_mssv = GTK_WIDGET(gtk_builder_get_object(builder, "entry_mssv"));

    if (!entry_name || !entry_mssv) {
        g_print("Error: Entry widgets not found\n");
        return;
    }

    const gchar *name = gtk_entry_get_text(GTK_ENTRY(entry_name));
    const gchar *mssv = gtk_entry_get_text(GTK_ENTRY(entry_mssv));

    char name_buf[100] = "";
    char mssv_buf[100] = "";
    if (name) strncpy(name_buf, name, sizeof(name_buf));
    if (mssv) strncpy(mssv_buf, mssv, sizeof(mssv_buf));
    printf("%s,%s",name_buf,mssv_buf);

    searching(students, mssv_buf,name_buf);
    reload_data(treeview,"stu.txt");

}
//

//add button and save button

void on_save_button_clicked(GtkButton *button, gpointer user_data) {
    printf("run_save\n");
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *stu = app_data->students;
    GtkTreeView *treeview = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview"));
    long i = 0;
    char m[50];
    printf("run_save1\n");
    
    GtkWidget *add_MSSV= GTK_WIDGET(gtk_builder_get_object(builder, "add_MSSV"));
    GtkWidget *add_name = GTK_WIDGET(gtk_builder_get_object(builder, "add_name"));
    GtkWidget *add_department = GTK_WIDGET(gtk_builder_get_object(builder, "add_department"));
    GtkWidget *add_day = GTK_WIDGET(gtk_builder_get_object(builder, "add_day"));
    GtkWidget *add_month = GTK_WIDGET(gtk_builder_get_object(builder, "add_month"));
    GtkWidget *add_year = GTK_WIDGET(gtk_builder_get_object(builder, "add_year"));
    GtkWidget *add_num = GTK_WIDGET(gtk_builder_get_object(builder, "add_num"));
    GtkWidget *add_address = GTK_WIDGET(gtk_builder_get_object(builder, "add_address"));
    GtkWidget *add_class = GTK_WIDGET(gtk_builder_get_object(builder, "add_class"));
    GtkWidget *add_math = GTK_WIDGET(gtk_builder_get_object(builder, "add_math"));
    GtkWidget *add_lit = GTK_WIDGET(gtk_builder_get_object(builder, "add_lit"));
    GtkWidget *add_eng = GTK_WIDGET(gtk_builder_get_object(builder, "add_eng"));
    printf("run_save2\n");
    const gchar *mssv = gtk_entry_get_text(GTK_ENTRY(add_MSSV));
    strcpy(m,mssv+3);
    i=atoi(m);
    const gchar *name = gtk_entry_get_text(GTK_ENTRY(add_name));
    const gchar *department = gtk_entry_get_text(GTK_ENTRY(add_department));
    const gchar *day = gtk_entry_get_text(GTK_ENTRY(add_day));
    const gchar *month = gtk_entry_get_text(GTK_ENTRY(add_month));
    const gchar *year = gtk_entry_get_text(GTK_ENTRY(add_year));
    const gchar *birth = g_strdup_printf("%s/%s/%s", day, month, year);
    const gchar *num = gtk_entry_get_text(GTK_ENTRY(add_num));
    const gchar *address = gtk_entry_get_text(GTK_ENTRY(add_address));
    const gchar *class_name = gtk_entry_get_text(GTK_ENTRY(add_class));
    const gchar *math = gtk_entry_get_text(GTK_ENTRY(add_math));
    const gchar *lit = gtk_entry_get_text(GTK_ENTRY(add_lit));
    const gchar *eng = gtk_entry_get_text(GTK_ENTRY(add_eng));

    char *endptr;
    float mathnum = strtof(math, &endptr);
    if (*endptr != '\0') {
        g_printerr("Invalid math score: %s\n", math);
        return;
    }

    float litnum = strtof(lit, &endptr);
    if (*endptr != '\0') {
        g_printerr("Invalid literature score: %s\n", lit);
        return;
    }

    float engnum = strtof(eng, &endptr);
    if (*endptr != '\0') {
        g_printerr("Invalid English score: %s\n", eng);
        return;
    }
    printf("run_save2\n");
    profile student;

    strncpy(student.MSSV, mssv, sizeof(student.MSSV) - 1);
    strncpy(student.NAME, name, sizeof(student.NAME) - 1);
    strncpy(student.department, department, sizeof(student.department) - 1);
    strncpy(student.DATE, birth, sizeof(student.DATE) - 1);
    strncpy(student.NUM, num, sizeof(student.NUM) - 1);
    strncpy(student.ADD, address, sizeof(student.ADD) - 1);
    strncpy(student.CLASS, class_name, sizeof(student.CLASS) - 1);
    student.math = mathnum;
    student.lit = litnum;
    student.eng = engnum;
    student.aver = (mathnum + litnum + engnum) / 3.0f;

    GtkWidget *label_error = GTK_WIDGET(gtk_builder_get_object(builder, "label_error"));
    char *error=studentadd(student);
    if(stu[i].MSSV[0] != '\0') {
        error = "ID already exists.";
    }
    gchar *error_text = g_strdup_printf("Error: %s", error);
    gtk_label_set_text(GTK_LABEL(label_error), error_text);
    if(error == NULL)
    {
        gtk_label_set_text(GTK_LABEL(label_error), "No error.");
    }
    if(error == NULL)
    {
        printf("MSSV: %s\n", student.MSSV);
        printf("Name: %s\n", student.NAME);
        printf("Department: %s\n", student.department);
        printf("Birth: %s\n", student.DATE);
        printf("Number: %s\n", student.NUM);
        printf("Address: %s\n", student.ADD);
        printf("Class: %s\n", student.CLASS);
        printf("Math: %.2f\n", student.math);
        printf("Literature: %.2f\n", student.lit);
        printf("English: %.2f\n", student.eng);
        printf("Average: %.2f\n", student.aver);
        printf("run_save3\n");
        stu[i]=student;
        printdata(stu,i); // Print data to file
        printdatareverse(student); // Print data to file
        reload_data1(treeview, "stu.txt");
        printf("save_button clicked\n");
        printf("save_complete\n");
    }

}
//
void on_save_button1_clicked(GtkButton *button, gpointer user_data) {
    printf("run_save1\n");
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *stu = app_data->students;
    GtkTreeView *treeview = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview"));
    printf("run_save11\n");
    long i = 0;
    char m[50];
    if(!selected_id) {
        g_print("Error: No ID selected\n");
        return;
    }
    printf("ID: %s\n", selected_id); 
    strncpy(m, selected_id + 3, sizeof(m) - 1);
    i=atoi(m);
    printf("ID: %d\n", i); 
    GtkWidget *add_name1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_name1"));
    GtkWidget *add_department1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_department1"));
    GtkWidget *add_day1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_day1"));
    GtkWidget *add_month1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_month1"));
    GtkWidget *add_year1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_year1"));
    GtkWidget *add_num1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_num1"));
    GtkWidget *add_address1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_address1"));
    GtkWidget *add_class1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_class1"));
    GtkWidget *add_math1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_math1"));
    GtkWidget *add_lit1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_lit1"));
    GtkWidget *add_eng1 = GTK_WIDGET(gtk_builder_get_object(builder, "add_eng1"));
    printf("run_save12\n");

    const gchar *name1 = gtk_entry_get_text(GTK_ENTRY(add_name1));
    const gchar *department1 = gtk_entry_get_text(GTK_ENTRY(add_department1));
    const gchar *day1 = gtk_entry_get_text(GTK_ENTRY(add_day1));
    const gchar *month1 = gtk_entry_get_text(GTK_ENTRY(add_month1));
    const gchar *year1 = gtk_entry_get_text(GTK_ENTRY(add_year1));
    const gchar *birth1 = g_strdup_printf("%s/%s/%s", day1, month1, year1);
    const gchar *num1 = gtk_entry_get_text(GTK_ENTRY(add_num1));
    const gchar *address1 = gtk_entry_get_text(GTK_ENTRY(add_address1));
    const gchar *class_name1 = gtk_entry_get_text(GTK_ENTRY(add_class1));
    const gchar *math1 = gtk_entry_get_text(GTK_ENTRY(add_math1));
    const gchar *lit1 = gtk_entry_get_text(GTK_ENTRY(add_lit1));
    const gchar *eng1 = gtk_entry_get_text(GTK_ENTRY(add_eng1));
    printf("run_save13\n");

    char *endptr;
    float mathnum = strtof(math1, &endptr);
    if (*endptr != '\0') {
        g_printerr("Invalid math score: %s\n", math1);
        return;
    }

    float litnum = strtof(lit1, &endptr);
    if (*endptr != '\0') {
        g_printerr("Invalid literature score: %s\n", lit1);
        return;
    }

    float engnum = strtof(eng1, &endptr);
    if (*endptr != '\0') {
        g_printerr("Invalid English score: %s\n", eng1);
        return;
    }
    printf("run_save14\n");
    profile student;
    strncpy(student.MSSV, selected_id, sizeof(student.MSSV) - 1);
    strncpy(student.NAME, name1, sizeof(student.NAME) - 1);
    strncpy(student.department, department1, sizeof(student.department) - 1);
    strncpy(student.DATE, birth1, sizeof(student.DATE) - 1);
    strncpy(student.NUM, num1, sizeof(student.NUM) - 1);
    strncpy(student.ADD, address1, sizeof(student.ADD) - 1);
    strncpy(student.CLASS, class_name1, sizeof(student.CLASS) - 1);
    student.math = mathnum;
    student.lit = litnum;
    student.eng = engnum;
    student.aver = (mathnum + litnum + engnum) / 3.0f;

    printf("run_check\n");
    GtkWidget *label_error1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_error1"));
    char *error1=studentadd(student);
    gchar *error_text1 = g_strdup_printf("Error: %s", error1);
    gtk_label_set_text(GTK_LABEL(label_error1), error_text1);
    if(error1 == NULL)
    {
        gtk_label_set_text(GTK_LABEL(label_error1), "No error.");
    }

    if(error1 == NULL)
    {   
        printf("run_delete_ID:%d\n",i);
        delete_data(stu,i); 
        printf("run_update\n");
        printf("MSSV: %s\n", student.MSSV);
        printf("Name: %s\n", student.NAME);
        printf("Department: %s\n", student.department);
        printf("Birth: %s\n", student.DATE);
        printf("Number: %s\n", student.NUM);
        printf("Address: %s\n", student.ADD);
        printf("Class: %s\n", student.CLASS);
        printf("Math: %.2f\n", student.math);
        printf("Literature: %.2f\n", student.lit);
        printf("English: %.2f\n", student.eng);
        printf("Average: %.2f\n", student.aver);
        printf("run_save13\n");
        stu[i]=student;
        printdata(stu,i); // Print data to file
        printdatareverse(student); // Print data to file
        reload_data1(treeview, "stu.txt");
        printf("save1_button clicked\n");
        printf("save1_complete\n");
    }
}//sửa đổi thông tintin

//
void on_add_button_clicked(GtkButton *button, gpointer user_data) {
    printf("run_add\n");
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    GtkWidget *window_add = GTK_WIDGET(gtk_builder_get_object(builder, "window_add"));
    g_signal_connect(window_add, "delete-event", G_CALLBACK(gtk_widget_hide_on_delete), NULL);
    if (!window_add) {
        g_print("Error: Window_add widget not found\n");
        g_object_unref(builder);
    }
    else gtk_widget_show_all(window_add);

}
//

//
void on_changes_button_clicked(GtkButton *button, gpointer user_data) {
    printf("run_changes\n");
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    GtkWidget *window_add1 = GTK_WIDGET(gtk_builder_get_object(builder, "window_add1"));
    g_signal_connect(window_add1, "delete-event", G_CALLBACK(gtk_widget_hide_on_delete), NULL);
    if (!window_add1) {
        g_print("Error: Window_add widget not found\n");
        g_object_unref(builder);
    }
    else gtk_widget_show_all(window_add1);
}

void on_delete_button_clicked(GtkButton *button, gpointer user_data) {
    printf("run_delete\n");
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *students = app_data->students;
    long i = 0;
    const char *m;
    if(!selected_id) {
        g_print("Error: No ID selected\n");
        return;
    }
    printf("ID: %s\n", selected_id);
    m=selected_id+3;
    i=atoi(m);
    printf("MSSV: %s\n", students[i].MSSV);
    printf("ID: %d\n", i);
    delete_data(students, i);
    students[i].MSSV[0] = '\0';
    students[i].NAME[0] = '\0';
    students[i].department[0] = '\0';
    students[i].DATE[0] = '\0';
    students[i].NUM[0] = '\0';
    students[i].ADD[0] = '\0';
    students[i].CLASS[0] = '\0';
    students[i].math = 0.0f;
    students[i].lit = 0.0f;
    students[i].eng = 0.0f;
    students[i].aver = 0.0f;

    
    printf("delete_button clicked\n");
    printf("delete_complete\n");
    selected_id = g_strdup(""); // Clear selected_id after deletion
    cleardata();
    GtkTreeView *treeview = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview"));
    reload_data(treeview, "stu.txt");
}
//

void on_HS018_button_clicked(GtkButton *button, gpointer *user_data) {
    printf("run_18\n");
    cleardata1();
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *students = app_data->students;
    profile *data18 = malloc(5000000 * sizeof(profile));
    studentdatadem(students);
    long count = data18print(students);
    printf("Sorted data: %ld\n", count);
    studentdata1(data18);

    quick_sort_descending(data18, 0, count + 1);
    cleardata1();
    for(int i = 0; i < count; i++) {
        printdata1(data18, i); // Print data to file
    }

    GtkTreeView *treeview1 = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview1"));
    reload_data(treeview1, "stu1.txt");
    printf("finished\n");
}

void on_HS019_button_clicked(GtkButton *button, gpointer *user_data) {
    printf("run_18\n");
    cleardata1();
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *students = app_data->students;
    profile *data19 = malloc(5000000 * sizeof(profile));
    studentdatadem(students);
    long count = data19print(students);
    printf("Sorted data: %ld\n", count);
    studentdata1(data19);

    quick_sort_descending(data19, 0, count + 1);
    cleardata1();
    for(int i = 0; i <= count; i++) {
        printdata1(data19, i); // Print data to file
    }
    GtkTreeView *treeview1 = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview1"));
    reload_data(treeview1, "stu1.txt");
    printf("finished\n");
}

void on_HS020_button_clicked(GtkButton *button, gpointer *user_data) {
    printf("run_20\n");
    cleardata1();
    AppData *app_data = (AppData *)user_data;
    GtkBuilder *builder = app_data->builder;
    profile *students = app_data->students;
    profile *data20 = malloc(5000000 * sizeof(profile));
    studentdatadem(students);
    long count = data20print(students);
    printf("Sorted data: %ld\n", count);
    studentdata1(data20);

    quick_sort_descending(data20, 0, count + 1);
    cleardata1();
    for(int i = 0; i <= count; i++) {
        printdata1(data20, i); // Print data to file
    }
    GtkTreeView *treeview1 = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview1"));
    reload_data(treeview1, "stu1.txt");
    printf("finished\n");
}
//

//ham chinh
int main(int argc, char *argv[]) {
    printf("run\n");
    //
    GtkBuilder *builder = NULL;
    GtkWidget *window = NULL;
    GtkTreeView *treeview = NULL;
    GtkTreeView *treeview1 = NULL;

    //
    cleardata();
    cleardata1();
    profile *stu = malloc(5000000 * sizeof(profile));
    profile *stu1 = malloc(5000000 * sizeof(profile));
    studentdata(stu);
    studentdatadem(stu1);
    //printf("%s",stu[2006474].NAME); // Print data for testing
    gtk_init(&argc, &argv);
    builder = gtk_builder_new();
    GError *error = NULL;

    if (!gtk_builder_add_from_file(builder, "interface.glade", &error)) {
        g_printerr("File UI error: %s\n", error->message);
        g_clear_error(&error);
        free(stu);
        return 1;
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    if (!window) {
        g_print("Error: Window widget not found\n");
        g_object_unref(builder);
        free(stu);
        return 1;
    }


    treeview = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview"));
    if (!treeview) {
        g_print("Error: Treeview widget not found\n");
        g_object_unref(builder);
        free(stu);
        return 1;
    }

    treeview1 = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeview1"));
    if (!treeview1) {
        g_print("Error: Treeview11 widget not found\n");
        g_object_unref(builder);
        free(stu);
        return 1;
    }
    AppData app_data = {
        .builder = builder,
        .students = stu,
        .student_count = 5000000 // Adjust if studentdata sets a specific count
    };
    AppData app_data1 = {
        .builder = builder,
        .students = stu1,
        .student_count = 5000000 // Adjust if studentdata sets a specific count
    };

    GList *data = read_data_from_file("stu.txt");
    if (data) {
        populate_treeview(treeview, data);
    } else {
        g_print("No data loaded from file\n");
    }

    GList *data1 = read_data_from_file("stu1.txt");
    if (data1) {
        populate_treeview(treeview1, data1);
    } else {
        g_print("No data loaded from file\n");
    }

    g_signal_connect(treeview, "row-activated", G_CALLBACK(on_row_activated), builder);
    g_signal_connect(treeview1, "row-activated", G_CALLBACK(on_row_activated), builder);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *search_button = GTK_WIDGET(gtk_builder_get_object(builder, "search_button"));
    if (search_button) {
        g_signal_connect(search_button, "clicked", G_CALLBACK(on_search_button_clicked), &app_data);
    } else {
        g_print("Error: Search button not found\n");
    }

    GtkWidget *save_button = GTK_WIDGET(gtk_builder_get_object(builder, "save_button"));
    if (save_button) {
        g_signal_connect(save_button, "clicked", G_CALLBACK(on_save_button_clicked), &app_data);
    } else {
        g_print("Error: save button not found\n");
    }

    GtkWidget *save_button1 = GTK_WIDGET(gtk_builder_get_object(builder, "save_button1"));
    if (save_button1) {
        g_signal_connect(save_button1, "clicked", G_CALLBACK(on_save_button1_clicked), &app_data);
    } else {
        g_print("Error: save button1 not found\n");
    }

    GtkWidget *add_button = GTK_WIDGET(gtk_builder_get_object(builder, "add_button"));
    if (add_button) {
        g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_button_clicked), &app_data);
        
    } else {
        g_print("Error: add button not found\n");
    }

    GtkWidget *changes_button = GTK_WIDGET(gtk_builder_get_object(builder, "changes_button"));
    if (changes_button) {
        g_signal_connect(changes_button, "clicked", G_CALLBACK(on_changes_button_clicked), &app_data);
    } else {
        g_print("Error: changes button not found\n");
    }

    GtkWidget *delete_button = GTK_WIDGET(gtk_builder_get_object(builder, "delete_button"));
    if (delete_button) {
        g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_button_clicked), &app_data);
    } else {
        g_print("Error: delete button not found\n");
    }

    //show rank menu
    GtkWidget *HS018_button = GTK_WIDGET(gtk_builder_get_object(builder, "HS18_button"));
    if(HS018_button) {
        g_signal_connect(HS018_button, "clicked", G_CALLBACK(on_HS018_button_clicked), &app_data1);
        printf("%d\n",app_data1.student_count);
    } else {
        g_print("Error: HS018 button not found\n");
    }

    GtkWidget *HS019_button = GTK_WIDGET(gtk_builder_get_object(builder, "HS19_button"));
    if(HS019_button) {
        g_signal_connect(HS019_button, "clicked", G_CALLBACK(on_HS019_button_clicked), &app_data1);
    } else {
        g_print("Error: HS019 button not found\n");
    }

    GtkWidget *HS020_button = GTK_WIDGET(gtk_builder_get_object(builder, "HS20_button"));
    if(HS020_button) {
        g_signal_connect(HS020_button, "clicked", G_CALLBACK(on_HS020_button_clicked), &app_data1);
    } else {
        g_print("Error: HS020 button not found\n");
    }
    //
    gtk_widget_show_all(window);
    gtk_main();

    if (person) {
        g_free(person); // Free person if allocated
    }
    free_person_list(data);
    free_person_list(data1);
    g_object_unref(builder);
    free(stu);
    return 0;
}