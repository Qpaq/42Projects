INSERT INTO ft_table (nom, date_de_creation) VALUES `SELECT nom, date_naissance, LEN(nom) AS len_nom FROM fiche_personne WHERE len_nom < 9, nom LIKE '%a%' ORDER BY nom LIMIT 10`;
