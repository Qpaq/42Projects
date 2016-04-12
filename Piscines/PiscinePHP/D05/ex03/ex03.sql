INSERT INTO ft_table (nom, date_de_creation) VALUES `SELECT nom, date_naissance FROM fiche_personne WHERE LEN(nom) < 9, nom LIKE '%a%' ORDER BY nom LIMIT 10`;
