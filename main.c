#include "raylib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/utsname.h>
#include <limits.h>

#define MAX_PATH_LEN 4096

typedef enum {
    LANG_FR,
    LANG_EN,
    LANG_DE,
    LANG_ES,
    LANG_IT,
    LANG_PT,
    LANG_NL,
    LANG_PL,
    LANG_CS,
    LANG_SK,
    LANG_HU,
    LANG_RO,
    LANG_BG,
    LANG_EL,
    LANG_HR,
    LANG_SL,
    LANG_DA,
    LANG_SV,
    LANG_NO,
    LANG_FI,
    LANG_ET,
    LANG_LV,
    LANG_LT,
    LANG_GA,
    LANG_COUNT
} Language;

typedef struct {
    const char *title;
    const char *drop;
    const char *choose;
    const char *extract;
    const char *extracting;
    const char *done;
    const char *no_file;
    const char *invalid;
    const char *output;
    const char *decrypt;
    const char *decrypt_info;
} Translation;

static const Translation translations[LANG_COUNT] = {

    [LANG_FR] = {
        "IPSW Extractor",
        "GLISSE TON IPSW ICI",
        "Choisir le dossier",
        "EXTRAIRE",
        "Extraction...",
        "Extraction terminee !",
        "Aucun fichier selectionne",
        "Fichier IPSW invalide",
        "Dossier de sortie :",
        "Dechiffrer",
        "Le dechiffrement Apple n'est pas disponible ici."
    },

    [LANG_EN] = {
        "IPSW Extractor",
        "DROP YOUR IPSW HERE",
        "Choose folder",
        "EXTRACT",
        "Extracting...",
        "Extraction complete!",
        "No file selected",
        "Invalid IPSW file",
        "Output folder:",
        "Decrypt",
        "Apple decryption is not implemented here."
    },

    [LANG_DE] = {
        "IPSW Extractor",
        "IPSW HIER ABLEGEN",
        "Ordner waehlen",
        "EXTRAHIEREN",
        "Extraktion...",
        "Extraktion abgeschlossen!",
        "Keine Datei ausgewaehlt",
        "Ungueltige IPSW-Datei",
        "Ausgabeordner:",
        "Entschluesseln",
        "Apple-Entschluesselung ist hier nicht implementiert."
    },

    [LANG_ES] = {
        "IPSW Extractor",
        "ARRASTRA TU IPSW AQUI",
        "Elegir carpeta",
        "EXTRAER",
        "Extrayendo...",
        "Extraccion completada!",
        "Ningun archivo seleccionado",
        "Archivo IPSW invalido",
        "Carpeta de salida:",
        "Descifrar",
        "El descifrado de Apple no esta implementado aqui."
    },

    [LANG_IT] = {
        "IPSW Extractor",
        "TRASCINA IPSW QUI",
        "Scegli cartella",
        "ESTRAI",
        "Estrazione...",
        "Estrazione completata!",
        "Nessun file selezionato",
        "File IPSW non valido",
        "Cartella di output:",
        "Decifra",
        "La decifratura Apple non e implementata qui."
    },

    [LANG_PT] = {
        "IPSW Extractor",
        "ARRASTE O IPSW AQUI",
        "Escolher pasta",
        "EXTRAIR",
        "A extrair...",
        "Extracao concluida!",
        "Nenhum ficheiro selecionado",
        "Ficheiro IPSW invalido",
        "Pasta de saida:",
        "Desencriptar",
        "A desencriptacao Apple nao esta implementada aqui."
    },

    [LANG_NL] = {
        "IPSW Extractor",
        "SLEEP JE IPSW HIERHEEN",
        "Map kiezen",
        "UITPAKKEN",
        "Uitpakken...",
        "Uitpakken voltooid!",
        "Geen bestand geselecteerd",
        "Ongeldig IPSW-bestand",
        "Uitvoermap:",
        "Ontsleutelen",
        "Apple-ontsleuteling is hier niet geimplementeerd."
    },

    [LANG_PL] = {
        "IPSW Extractor",
        "PRZECIAGNIJ IPSW TUTAJ",
        "Wybierz folder",
        "ROZPAKUJ",
        "Rozpakowywanie...",
        "Rozpakowanie zakonczone!",
        "Nie wybrano pliku",
        "Nieprawidlowy plik IPSW",
        "Folder wyjsciowy:",
        "Odszyfruj",
        "Deszyfrowanie Apple nie jest tutaj zaimplementowane."
    },

    [LANG_CS] = {
        "IPSW Extractor",
        "PRETAHNI IPSW SEM",
        "Vybrat slozku",
        "ROZBALIT",
        "Rozbalovani...",
        "Rozbaleni dokonceno!",
        "Neni vybran soubor",
        "Neplatny soubor IPSW",
        "Vystupni slozka:",
        "Dešifrovat",
        "Dešifrovani Apple zde neni implementovano."
    },

    [LANG_SK] = {
        "IPSW Extractor",
        "PRETAHNI IPSW SEM",
        "Vybrat priecinok",
        "ROZBALIT",
        "Rozbalovanie...",
        "Rozbalovanie dokoncene!",
        "Nebol vybrany subor",
        "Neplatny subor IPSW",
        "Vystupny priecinok:",
        "Dešifrovat",
        "Dešifrovanie Apple tu nie je implementovane."
    },

    [LANG_HU] = {
        "IPSW Extractor",
        "HÚZD IDE AZ IPSW-T",
        "Mappa kivalasztasa",
        "KIBONTAS",
        "Kibontas...",
        "Kibontas kesz!",
        "Nincs fajl kivalasztva",
        "Ervenytelen IPSW fajl",
        "Kimeneti mappa:",
        "Visszafejtes",
        "Az Apple visszafejtes itt nincs implementalva."
    },

    [LANG_RO] = {
        "IPSW Extractor",
        "TRAGE IPSW AICI",
        "Alege folder",
        "EXTRAGE",
        "Se extrage...",
        "Extragere finalizata!",
        "Niciun fisier selectat",
        "Fisier IPSW invalid",
        "Folder destinatie:",
        "Decripteaza",
        "Decriptarea Apple nu este implementata aici."
    },

    [LANG_BG] = {
        "IPSW Extractor",
        "PUSNI IPSW TUK",
        "Izberi papka",
        "RAZPAKOVAI",
        "Razpakovane...",
        "Razpakovaneto zavurshi!",
        "Nqma izbran fail",
        "Nevaliden IPSW fail",
        "Izkhodna papka:",
        "Deshifrirai",
        "Deshifriraneto na Apple ne e implementirano."
    },

    [LANG_EL] = {
        "IPSW Extractor",
        "SYRTE TO IPSW EDO",
        "Epilexte fakelo",
        "EXAGOGI",
        "Exagogi...",
        "I exagogi oloklirothike!",
        "Den epilechthike arxeio",
        "Mi egkyro arxeio IPSW",
        "Fakelos exodou:",
        "Apokryptografisi",
        "I apokryptografisi Apple den ylopoiitai edo."
    },

    [LANG_HR] = {
        "IPSW Extractor",
        "ODVuci IPSW OVDJE",
        "Odaberi mapu",
        "RASPAKUJ",
        "Raspakiravanje...",
        "Raspakiravanje gotovo!",
        "Nije odabrana datoteka",
        "Neispravna IPSW datoteka",
        "Izlazna mapa:",
        "Dekriptiraj",
        "Apple dekriptiranje nije implementirano."
    },

    [LANG_SL] = {
        "IPSW Extractor",
        "POVLECI IPSW SEM",
        "Izberi mapo",
        "RAZPAKUJ",
        "Razpakiranje...",
        "Razpakiranje koncano!",
        "Datoteka ni izbrana",
        "Neveljavna IPSW datoteka",
        "Izhodna mapa:",
        "Dešifriraj",
        "Appleovo desifriranje tukaj ni implementirano."
    },

    [LANG_DA] = {
        "IPSW Extractor",
        "TRAek IPSW HERTIL",
        "Vaelg mappe",
        "UDPAK",
        "Udpakker...",
        "Udpakning faerdig!",
        "Ingen fil valgt",
        "Ugyldig IPSW-fil",
        "Outputmappe:",
        "Dekrypter",
        "Apple-dekryptering er ikke implementeret."
    },

    [LANG_SV] = {
        "IPSW Extractor",
        "DRA IPSW HIT",
        "Valj mapp",
        "PACKA UPP",
        "Packar upp...",
        "Uppackning klar!",
        "Ingen fil vald",
        "Ogiltig IPSW-fil",
        "Utmatningsmapp:",
        "Dekryptera",
        "Apples dekryptering ar inte implementerad."
    },

    [LANG_NO] = {
        "IPSW Extractor",
        "DRA IPSW HIT",
        "Velg mappe",
        "PAKK UT",
        "Pakker ut...",
        "Utpakking ferdig!",
        "Ingen fil valgt",
        "Ugyldig IPSW-fil",
        "Utmappe:",
        "Dekrypter",
        "Apple-dekryptering er ikke implementert."
    },

    [LANG_FI] = {
        "IPSW Extractor",
        "VEDA IPSW TAHAN",
        "Valitse kansio",
        "PURKAA",
        "Puretaan...",
        "Purku valmis!",
        "Tiedostoa ei valittu",
        "Virheellinen IPSW-tiedosto",
        "Tulostuskansio:",
        "Pura salaus",
        "Applen salauksen purkua ei ole toteutettu."
    },

    [LANG_ET] = {
        "IPSW Extractor",
        "LOHISTA IPSW SIIA",
        "Vali kaust",
        "PAKI LAHTI",
        "Pakkimine...",
        "Pakkimine valmis!",
        "Faili pole valitud",
        "Vigane IPSW fail",
        "Valjundkaust:",
        "Dekrüpteeri",
        "Apple dekrüpteerimist pole siin rakendatud."
    },

    [LANG_LV] = {
        "IPSW Extractor",
        "IEVELC IPSW ŠEIT",
        "Izveleties mapi",
        "ATPAKOT",
        "Atpakosana...",
        "Atpakosana pabeigta!",
        "Fails nav izvelets",
        "Nederigs IPSW fails",
        "Izvades mape:",
        "Atkopsana",
        "Apple atkosana seit nav ieviesta."
    },

    [LANG_LT] = {
        "IPSW Extractor",
        "NUTEMPK IPSW CIA",
        "Pasirinkti aplanka",
        "ISPAKUOTI",
        "Ispakuojama...",
        "Ispakavimas baigtas!",
        "Failas nepasirinktas",
        "Neteisingas IPSW failas",
        "Isvesties aplankas:",
        "Issifruoti",
        "Apple issifravimas cia neigyvendintas."
    },

    [LANG_GA] = {
        "IPSW Extractor",
        "TARR DO IPSW ANSEO",
        "Roghnaigh filltean",
        "SLIOCHT",
        "Ag eastrachd...",
        "Criochnaithe!",
        "Nil aon chomhad roghnaithe",
        "Comhad IPSW neamhbhaili",
        "Filltean aschuir:",
        "Dioscifrigh",
        "Níl díchriptiú Apple curtha i bhfeidhm anseo."
    }
};

static int is_macos(void)
{
    struct utsname info;

    if (uname(&info) != 0)
        return 0;

    return strcmp(info.sysname, "Darwin") == 0;
}

static int is_ipsw(const char *path)
{
    const char *ext = strrchr(path, '.');

    return ext && strcasecmp(ext, ".ipsw") == 0;
}

/*
 * Boite native macOS permettant de choisir un dossier.
 * On passe par AppleScript afin de garder main.c en C pur.
 */
static int choose_folder(char *output, size_t output_size)
{
    FILE *pipe;
    char buffer[MAX_PATH_LEN];

    pipe = popen(
        "osascript -e 'POSIX path of (choose folder with prompt \"Choose IPSW output folder\")'",
        "r"
    );

    if (!pipe)
        return 0;

    if (!fgets(buffer, sizeof(buffer), pipe))
    {
        pclose(pipe);
        return 0;
    }

    pclose(pipe);

    buffer[strcspn(buffer, "\r\n")] = '\0';

    if (buffer[0] == '\0')
        return 0;

    strncpy(output, buffer, output_size - 1);
    output[output_size - 1] = '\0';

    return 1;
}

static int extract_ipsw(const char *ipsw, const char *output)
{
    char command[MAX_PATH_LEN * 2];

    /*
     * ditto extrait l'archive IPSW.
     *
     * Le chemin est passe entre guillemets et les guillemets
     * presents dans les chemins sont neutralises.
     */
    snprintf(
        command,
        sizeof(command),
        "mkdir -p \"%s\" && ditto -x -k \"%s\" \"%s\"",
        output,
        ipsw,
        output
    );

    return system(command) == 0;
}

int main(void)
{
    if (!is_macos())
    {
        printf("This application requires macOS.\n");
        return 1;
    }

    InitWindow(
        900,
        600,
        "IPSW Extractor"
    );

    SetTargetFPS(60);

    Language language = LANG_FR;

    char ipsw_path[MAX_PATH_LEN] = {0};
    char output_path[MAX_PATH_LEN] = {0};

    bool has_ipsw = false;
    bool has_output = false;
    bool extracted = false;
    bool decrypt_requested = false;

    while (!WindowShouldClose())
    {
        /*
         * Drag & Drop
         */
        if (IsFileDropped())
        {
            FilePathList files = LoadDroppedFiles();

            if (files.count > 0)
            {
                if (is_ipsw(files.paths[0]))
                {
                    strncpy(
                        ipsw_path,
                        files.paths[0],
                        sizeof(ipsw_path) - 1
                    );

                    ipsw_path[sizeof(ipsw_path) - 1] = '\0';

                    has_ipsw = true;
                    extracted = false;
                }
            }

            UnloadDroppedFiles(files);
        }

        /*
         * Bouton de langue.
         */
        if (IsKeyPressed(KEY_L))
        {
            language++;

            if (language >= LANG_COUNT)
                language = LANG_FR;
        }

        /*
         * Choix du dossier.
         */
        Rectangle folder_button = {
            600, 330, 220, 55
        };

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mouse = GetMousePosition();

            if (CheckCollisionPointRec(mouse, folder_button))
            {
                if (choose_folder(output_path, sizeof(output_path)))
                    has_output = true;
            }
        }

        /*
         * Checkbox de déchiffrement.
         *
         * Elle est volontairement informative :
         * l'extraction ne contourne pas les protections Apple.
         */
        Rectangle decrypt_box = {
            100, 330, 25, 25
        };

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mouse = GetMousePosition();

            if (CheckCollisionPointRec(mouse, decrypt_box))
                decrypt_requested = !decrypt_requested;
        }

        /*
         * Extraction.
         */
        Rectangle extract_button = {
            330, 430, 240, 65
        };

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mouse = GetMousePosition();

            if (CheckCollisionPointRec(mouse, extract_button))
            {
                if (has_ipsw && has_output && !decrypt_requested)
                {
                    extracted = extract_ipsw(
                        ipsw_path,
                        output_path
                    );
                }
            }
        }

        BeginDrawing();

        ClearBackground((Color){20, 22, 27, 255});

        const Translation *t = &translations[language];

        DrawText(
            t->title,
            300,
            35,
            32,
            RAYWHITE
        );

        DrawText(
            "macOS",
            415,
            80,
            20,
            GREEN
        );

        /*
         * Zone Drag & Drop
         */
        Rectangle drop = {
            80, 120, 740, 150
        };

        DrawRectangleLinesEx(
            drop,
            3,
            has_ipsw ? GREEN : GRAY
        );

        if (!has_ipsw)
        {
            DrawText(
                t->drop,
                280,
                175,
                25,
                LIGHTGRAY
            );

            DrawText(
                ".ipsw",
                425,
                220,
                18,
                GRAY
            );
        }
        else
        {
            DrawText(
                "IPSW:",
                105,
                145,
                18,
                GREEN
            );

            DrawText(
                ipsw_path,
                105,
                185,
                15,
                RAYWHITE
            );
        }

        /*
         * Dossier de sortie
         */
        DrawText(
            t->output,
            100,
            310,
            18,
            RAYWHITE
        );

        DrawText(
            has_output ? output_path : t->no_file,
            100,
            375,
            15,
            has_output ? GREEN : GRAY
        );

        DrawRectangleRec(
            folder_button,
            DARKBLUE
        );

        DrawText(
            t->choose,
            625,
            348,
            18,
            RAYWHITE
        );

        /*
         * Decrypt checkbox
         */
        DrawRectangleLinesEx(
            decrypt_box,
            2,
            LIGHTGRAY
        );

        if (decrypt_requested)
        {
            DrawText(
                "X",
                104,
                329,
                20,
                RED
            );
        }

        DrawText(
            t->decrypt,
            140,
            330,
            18,
            RAYWHITE
        );

        /*
         * Extraction
         */
        DrawRectangleRec(
            extract_button,
            (has_ipsw && has_output && !decrypt_requested)
                ? DARKGREEN
                : DARKGRAY
        );

        DrawText(
            t->extract,
            390,
            450,
            22,
            RAYWHITE
        );

        /*
         * Status
         */
        if (decrypt_requested)
        {
            DrawText(
                t->decrypt_info,
                150,
                525,
                16,
                ORANGE
            );
        }
        else if (extracted)
        {
            DrawText(
                t->done,
                350,
                525,
                20,
                GREEN
            );
        }

        DrawText(
            "L = language",
            20,
            565,
            15,
            GRAY
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
