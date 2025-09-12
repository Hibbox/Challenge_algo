#include <iostream>
#include <string>
#include <vector>


std::string base64_encode(const std::string &input) {

    const std::string alphabet_char = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

    // regroupement par 3 octet

    std::string encoded;
    int i, j = 0;
    unsigned char buf_temp_3o[3];
    

    // 1. lecture sequentielle
    for(const auto &compteur: input ){
        //1.1accumuler octet dans la boucle et calculer les indices
        buf_temp_3o[j++] = compteur; // on stocke l'octet actuel
        if(j == 3){
           int index1 = (buf_temp_3o[0] >> 2); // Décaler de 2 positions à droite élimine les 2 bits de poids faible 11010110 >> 2 = 00110101 (garde les 6 premiers)
           int index2 = ((buf_temp_3o[0] & 0x03) << 4) | (buf_temp_3o[1] >> 4); // Décaler ces 2 bits de 4 positions à gauche et Le AND garde uniquement où il y a des 1
           int index3 = ((buf_temp_3o[1] & 0x0F) << 2) | (buf_temp_3o[2] >> 6) ; // 4 bits de poids faible du 2ème octet + 2 bits de poids fort du
           int index4 = (buf_temp_3o[2] & 0x3F); // 6 bits de poids faible du 3ème octet

            encoded += alphabet_char[index1];
            encoded += alphabet_char[index2];
            encoded += alphabet_char[index3];
            encoded += alphabet_char[index4];
            j = 0;
        }
    }
        if(j == 1) {
      // Il reste 1 octet dans buf_temp_3o[0]
        int index1 = (buf_temp_3o[0] >> 2);
        int index2 = ((buf_temp_3o[0] & 0x03) << 4);  // Seulement bits, le reste est 0
      
        encoded += alphabet_char[index1];
        encoded += alphabet_char[index2];
        encoded += "==";  // 2 signes égal pour padding
    }
        else if(j == 2) {
      // Il reste 2 octets dans buf_temp_3o[0] et buf_temp_3o[1]
        int index1 = (buf_temp_3o[0] >> 2);
        int index2 = ((buf_temp_3o[0] & 0x03) << 4) |
    (buf_temp_3o[1] >> 4);
        int index3 = ((buf_temp_3o[1] & 0x0F) << 2);  // 4 bits, le reste est 0

        encoded += alphabet_char[index1];
        encoded += alphabet_char[index2];
        encoded += alphabet_char[index3];
        encoded += "=";  // 1 signe égal pour padding
        
    }

    return encoded;
}

std::string base64_decode(const std::string &input) {
    const std::string base64_chars = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    
    std::string decoded;
    int i = 0;
    int j = 0;
    int in_len = input.size();
    unsigned char char_array_4[4], char_array_3[3];

    // prepare une table de recherche pour chercher les caractere plus vite
    int decoding_table[256];
    for (int i = 0; i < 256; i++) {
        decoding_table[i] = -1;
    }
    for (int i = 0; i < 64; i++) {
        decoding_table[base64_chars[i]] = i;
    }
    
    // Traiter chaque caractère
    for (const auto &c : input) {
        if (c == '=') break; // Arrêter au padding
        
        char_array_4[i++] = c;
        if (i == 4) {
            for (i = 0; i < 4; i++) {
                char_array_4[i] = decoding_table[char_array_4[i]];
            }
            
            char_array_3[0] = (char_array_4[0] << 2) | ((char_array_4[1] & 0x30) >> 4); /* on reconstitue le premier octet en prenant et les 2 premier bit de l'octet suivant par ex 0x30 -> 00110000,
                                                                                        permet d'isoler les 2 bits de poid fort de la deuxieme valeur puis on décale ces 2 bits de 4 positions vers la droite pour les placer en position de bits de poids faible.*/
            char_array_3[1] = ((char_array_4[1] & 0x0F) << 4) | ((char_array_4[2] & 0x3C) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x03) << 6) | char_array_4[3];
            
            for (i = 0; i < 3; i++) {
                decoded += char_array_3[i];
            }
            i = 0;
        }
    }
    
    // Gérer le dernier groupe incomplet
    if (i) {
        for (j = i; j < 4; j++) {
            char_array_4[j] = 0;
        }
        
        for (j = 0; j < 4; j++) {
            char_array_4[j] = decoding_table[char_array_4[j]];
        }
        
        char_array_3[0] = (char_array_4[0] << 2) | ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0x0F) << 4) | ((char_array_4[2] & 0x3C) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x03) << 6) | char_array_4[3];
        
        for (j = 0; j < i - 1; j++) {
            decoded += char_array_3[j];
        }
    }
    
    return decoded;
}

  int main() {
      // Tester votre fonction
      std::string test = "Q29tbWVudCByZXRyb3V2ZXIgbGVzIGVudHJlcHJpc2VzIHBpcmF0w6llcyBwYXIgbGUgcmFuc29td2FyZSBBa2lyYSA/Vm91cyB0cm91dmV6IGxhIHF1ZXN0aW9uIGZhY2lsZSA/IFBvc3R1bGV6IHN1ciBjZXR0ZSBhbm5vbmNlIGV0IHZlbmV6IHRyYXZhaWxsZXIgYXZlYyBub3VzICE=";
      std::string resultat = base64_decode(test);
      std::cout << "decodé: " << resultat << std::endl;
      return 0;
  }