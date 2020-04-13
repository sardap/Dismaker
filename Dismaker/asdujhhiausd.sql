CREATE TABLE Strings ( 
    string_id VARCHAR(255), 
    string NVARCHAR(2047), 
    PRIMARY KEY (string_id) 
); 
CREATE TABLE Feelings ( 
    feeling_id VARCHAR(255), 
    feeling_name VARCHAR(255), 
    PRIMARY KEY (feeling_id), 
    FOREIGN KEY (feeling_name) REFERENCES Strings(string_id) 
); 
CREATE TABLE Images ( 
    image_id VARCHAR(255), 
    file_location NVARCHAR(260), 
    PRIMARY KEY (image_id) 
); 
CREATE TABLE Characters( 
    char_id VARCHAR(255), 
    char_name VARCHAR(255), 
    char_description VARCHAR(255), 
    char_portrait VARCHAR(255), 
    PRIMARY KEY (char_id), 
    FOREIGN KEY (char_name) REFERENCES Strings(string_id), 
    FOREIGN KEY (char_description) REFERENCES Strings(string_id), 
    FOREIGN KEY (char_portrait) REFERENCES Images(image_id) 
); 
CREATE TABLE CharecterFeelings( 
    feeling_id VARCHAR(255), 
    char_id VARCHAR(255), 
    feeling_value SMALLINT, 
    PRIMARY KEY(feeling_id, char_id), 
    FOREIGN KEY (char_id) REFERENCES Characters(char_id), 
    FOREIGN KEY (feeling_id) REFERENCES Feelings(feeling_id)  
); 
CREATE TABLE DialogTree( 
    dialog_tree_id VARCHAR(255), 
    dialog_tree_background VARCHAR(255),  
    PRIMARY KEY (dialog_tree_id), 
    FOREIGN KEY (dialog_tree_background) REFERENCES Images(image_id) 
); 
CREATE TABLE Dialog( 
    dialog_id VARCHAR(255), 
    dialog_text VARCHAR(255), 
    PRIMARY KEY (dialog_id), 
    FOREIGN KEY (dialog_text) REFERENCES Strings(string_id) 
); 
ALTER TABLE DialogTree ADD dialog_tree_oppening_node VARCHAR(255) REFERENCES Dialog(dialog_id); 
ALTER TABLE Dialog ADD dialog_tree_id VARCHAR(255) REFERENCES DialogTree(dialog_tree_idid); 

CREATE TABLE CharcterDialogTrees( 
    dialog_tree_id VARCHAR(255), 
    char_id VARCHAR(255), 
    PRIMARY KEY (dialog_tree_id, char_id), 
    FOREIGN KEY (dialog_tree_id) REFERENCES DialogTree(dialog_tree_id), 
    FOREIGN KEY (char_id) REFERENCES Characters(char_id) 
); 
CREATE TABLE Options( 
    option_id INTEGER PRIMARY KEY, 
    dialog_id VARCHAR(255), 
    dialog_tree_id VARCHAR(255), 
    option_text VARCHAR(255), 
    FOREIGN KEY (dialog_id) REFERENCES Dialog(dialog_id), 
    FOREIGN KEY (dialog_tree_id) REFERENCES DialogTree(dialog_tree_id) 
); 
CREATE TABLE Effects( 
    effect_id INTEGER PRIMARY KEY, 
    option_id INTEGER, 
    dialog_id VARCHAR(255), 
    dialog_tree_id VARCHAR(255), 
    effect_command VARCHAR(1023), 
    FOREIGN KEY (option_id) REFERENCES Options(option_id), 
    FOREIGN KEY (dialog_id) REFERENCES Dialog(dialog_id), 
    FOREIGN KEY (dialog_tree_id) REFERENCES DialogTree(dialog_tree_id) 
);







INSERT INTO Strings VALUES('feeling_mad', 'mad'); 
INSERT INTO Feelings VALUES('mad', 'feeling_mad'); 
INSERT INTO Strings VALUES('pacman_name', 'pac-man'); 
INSERT INTO Strings VALUES('pacman_description', 'a yellow circle form a by gone era'); 
INSERT INTO Images  VALUES('pac-man', '\C:\\pac_man.jpg\'); 
INSERT INTO Characters VALUES('pac-man', 'pacman_name', 'pacman_description', 'pac-man'); 
INSERT INTO CharecterFeelings VALUES('mad', 'pac-man', 100); 
INSERT INTO Strings VALUES('pacman_greeting', 'g''day im pac-man'); 
INSERT INTO Strings VALUES('pacman_dialog_one_entrace', 'You need to come with me to free the souls of our fallen comardes'); 
INSERT INTO Strings VALUES('pacman_dialog_one_entrace_option_1', 'Woah that''s stupid'); 
INSERT INTO Strings VALUES('pacman_dialog_one_entrace_option_2', 'nice?'); 
INSERT INTO Strings VALUES('pacman_dialog_one_entrace_option_3', 'sure thing chicken wing'); 
INSERT INTO Images VALUES('pacman_dialog_tree_one', 'C:\\wakaqakamaze.jpg'); 
INSERT INTO DialogTree(dialog_tree_id, dialog_tree_background) VALUES('pacman_dialogtree_one', 'pacman_dialog_tree_one'); 
INSERT INTO Dialog(dialog_tree_id, dialog_id, dialog_text) VALUES( 'pacman_dialogtree_one', 'pacman_dialog_tree_one_one', 'pacman_dialog_one_entrace'); 
UPDATE DialogTree SET dialog_tree_oppening_node = 'pacman_dialog_tree_one_one' WHERE dialog_tree_id = 'pacman_dialogtree_one'; 
INSERT INTO CharcterDialogTrees VALUES('pacman_dialogtree_one', 'pac-man');
INSERT INTO Options(dialog_id, dialog_tree_id, option_text) VALUES('pacman_dialog_tree_one_one', 'pacman_dialogtree_one', 'pacman_dialog_one_entrace_option_1'); 
INSERT INTO Effects(option_id, dialog_id, dialog_tree_id, effect_command) VALUES((SELECT MAX(option_id) FROM Options), 'pacman_dialog_tree_one_one', 'pacman_dialogtree_one', 'TYPE = Procude TARGET = pacman_dialog_tree_one, pacman_dialog_two'); 
INSERT INTO Effects(option_id, dialog_id, dialog_tree_id, effect_command) VALUES((SELECT MAX(option_id) FROM Options), 'pacman_dialog_tree_one_one', 'pacman_dialogtree_one', 'TYPE = PlayMusic TARGET = C:\\Funtime.mp3'); 
INSERT INTO Options(dialog_id, dialog_tree_id, option_text) VALUES( 'pacman_dialog_tree_one_one', 'pacman_dialogtree_one', 'pacman_dialog_one_entrace_option_2'); 
INSERT INTO Options(dialog_id, dialog_tree_id, option_text) VALUES( 'pacman_dialog_tree_one_one', 'pacman_dialogtree_one', 'pacman_dialog_one_entrace_option_3');

SELECT e.effect_command
FROM Dialog d 
INNER JOIN Options o ON d.dialog_id = o.dialog_id 
INNER JOIN Effects e ON o.option_id = e.option_id 
WHERE d.dialog_id = 'pacman_dialog_tree_one_one';

SELECT * FROM Options;

SELECT e.effect_command FROM Dialog d INNER JOIN Options o ON d.dialog_id = o.dialog_id INNER JOIN Effects e ON o.option_id = e.option_id WHERE d.dialog_id = pacman_dialog_tree_one_one'