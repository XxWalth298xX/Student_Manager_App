#include "students.h"
#include "add_student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int count = 0;
const char *majors[] = {"SE","AI","IA","IS","IC","EL","CN","KR","JP","se","ai","ia","is","ic","el","cn","kr","jp"};

const char *group[] = {
    "SE01", "SE02", "se01", "se02",
    "AI01", "AI02", "ai01", "ai02",
    "IA01", "IA02", "ia01", "ia02",
    "IS01", "IS02", "is01", "is02",
    "IC01", "IC02", "ic01", "ic02",
    "EL01", "EL02", "el01", "el02",
    "CN01", "CN02", "cn01", "cn02",
    "KR01", "KR02", "kr01", "kr02",
    "JP01", "JP02", "jp01", "jp02",
};

//Kiểm tra tính hợp lệ của ID sinh viên
char* checkID(char *ID) {
    // Kiểm tra độ dài
    if (strlen(ID) != 10) {
        return "Invalid ID.";
    }
    // Kiểm tra tiền tố "HS0"
    if (ID[0] != 'H' || ID[1] != 'S' || ID[2] != '0') {
        return "Invalid ID.";
    }
    return "\0";
}
// Hàm kiểm tra tính hợp lệ của tên sinh viên
char* checkName(char *name) {
    // Kiểm tra độ dài tên
    if (strlen(name) == 0 || strlen(name) > 100) {
        return "Invalid name.";
    }

    // Kiểm tra từng từ trong chuỗi
    int i = 0;
    int isStartOfWord = 1; // Biến để xác định đầu từ
    while (name[i] != '\0') {
        if (isStartOfWord) {
            // Kiểm tra ký tự đầu tiên của từ phải là chữ hoa
            if (!isupper(name[i])) {
                return "Invalid name: Each word must start with an uppercase letter.";
            }
            isStartOfWord = 0; // Đã qua đầu từ
        } else {
            // Kiểm tra các ký tự còn lại phải là chữ cái hoặc khoảng trắng
            if (!isalpha(name[i]) && name[i] != ' ') {
                return "Invalid name: Contains invalid characters.";
            }
        }

        // Nếu gặp khoảng trắng, đánh dấu bắt đầu từ mới
        if (name[i] == ' ') {
            isStartOfWord = 1;
        }
        i++;
    }
    return "\0";
}

// Kiểm tra tính hợp lệ của ngày sinh
char* checkDateofBirth(int day, int month, int year) {
    if (year > 0) {
        if ((month >= 1) && (month <= 12)) {
            if (day > 0) {
                switch (month) {
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if ((day < 1) || (day > 31)) {
                            return "Invalid date.";
                        }
                        break;
                    case 4: case 6: case 9: case 11:
                        if ((day < 1) || (day > 30)){
                            return "Invalid date.";
                        }
                        break;
                    case 2:
                        if (((year%4==0) && (year%100!=0)) || (year%400==0)) {
                            if ((day < 1) || (day > 29)) {
                                return "Invalid date.";
                            }
                        } else if ((day < 1) || (day > 28)) {
                            return "Invalid date.";
                        }
                        break;
                    default:
                        return "Invalid date.";
                        break;
                }
            }
        } else {
            return "Invalid date.";
        }
    } else {
        return "Invalid date.";
    }
    return "\0";
}

// Kiểm tra tính hợp lệ của số điện thoại
char* isValidPhoneNumber(char *phone) {
    int len = strlen(phone);
    // Trường hợp bắt đầu bằng '0' => độ dài phải là 10
    if (phone[0] == '0') {
        if (len < 10) {
            return "Invalid phone number.";
        } else if (len == 10) { // Kiểm tra tất cả các ký tự đều là số
            for (int i = 0; i < 10; i++) {
                if (!isdigit(phone[i])) {
                    return "Invalid phone number.";
                }
                return "\0";
            }
        }
    }
    return "Invalid phone number.";
    // Các định dạng khác đều không hợp lệ
}

// Hàm kiểm tra xem có đúng ngành học không
char* checkdepartment(char *department) {
    for (int i = 0; i < sizeof(majors) / sizeof(majors[0]); i++) {
        if (strcmp(department, majors[i]) == 0) {
            return "\0"; // Ngành học hợp lệ
        }
    }
    return "Invalid department."; // Ngành học không hợp lệ
}

// Hàm kiểm tra xem có đúng lớp học không
char* checkgroup(char *classGroup) {
    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++) {
        if (strcmp(classGroup, group[i]) == 0) {
            return "\0"; // Lớp học hợp lệ
        }
    }
    return "Invalid class."; // Lớp học không hợp lệ
}

// Hàm kiểm tra điểm các môn học
char* checkscore(float score) {
    if ((score < 0) || (score > 10)) {
        return "Invalid score."; // Điểm không hợp lệ
    }
    return "\0"; // Điểm hợp lệ
}

// Hàm kiểm tra địa chỉ
char* checkaddress(char *address) {
    if (strlen(address) == 0) {
        return "Invalid address."; // Địa chỉ không hợp lệ
    }
    return "\0"; // Địa chỉ hợp lệ
}

// Hàm nhập thông tin sinh viên
char* studentadd(profile s) {
    //
    if(checkID(s.MSSV)!="\0"){
        return checkID(s.MSSV);
    }
    if(checkName(s.NAME)!="\0"){
        return checkName(s.NAME);
    }
    int day, month, year;
    char *token = strtok(s.DATE, "/-_");
    if (token != NULL) {
        day = atoi(token);
        token = strtok(NULL, "/-_");
    }
    if (token != NULL) {
        month = atoi(token);
        token = strtok(NULL, "/-_");
    }
    if (token != NULL) {
        year = atoi(token);
    } 
    if(checkdepartment(s.department)!="\0") return checkdepartment(s.department);
    if(checkDateofBirth(day, month, year)!="\0") return checkDateofBirth(day, month, year);
    if(isValidPhoneNumber(s.NUM)!="\0") return isValidPhoneNumber(s.NUM);
    if(checkaddress(s.ADD)!="\0") return checkaddress(s.ADD);
    if(checkgroup(s.CLASS)!="\0") return checkgroup(s.CLASS);
    if(checkscore(s.math)!="\0") return checkscore(s.math);
    if(checkscore(s.lit)!="\0") return checkscore(s.lit);
    if(checkscore(s.eng)!="\0") return checkscore(s.eng);
    // Kiểm tra xem ID đã tồn tại chưa
    //
    return NULL; // ID chưa tồn tại, có thể thêm sinh viên mới
    //them thong tin sinh vien vao danh sach
}
