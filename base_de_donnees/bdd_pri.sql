-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  mer. 10 jan. 2018 à 09:37
-- Version du serveur :  5.7.19
-- Version de PHP :  5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `bdd_pri`
--

-- --------------------------------------------------------

--
-- Structure de la table `clients`
--

DROP TABLE IF EXISTS `clients`;
CREATE TABLE IF NOT EXISTS `clients` (
  `Genre` varchar(100) NOT NULL,
  `Nom` varchar(100) NOT NULL,
  `Prenom` varchar(100) NOT NULL,
  `Groupe sanguin` varchar(100) NOT NULL,
  `Telephone` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `adresse` varchar(100) NOT NULL,
  `allergie` varchar(100) NOT NULL,
  `id` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `clients`
--

INSERT INTO `clients` (`Genre`, `Nom`, `Prenom`, `Groupe sanguin`, `Telephone`, `email`, `adresse`, `allergie`, `id`) VALUES
('Mâle', 'Bonneton', 'Maxime', 'O+', '06 40 52 52 30 ', 'maxime.bonneton@hotmail.fr', 'adresse de Monsieur Bonneton', 'aux arachides ', 1),
('Mâle', 'Courbon', 'Florian', 'O', '06 85 63 01 45', 'florian.courbon@hotmail.fr', 'adresse de Monsieur Courbon', 'au pollen', 2),
('Mâle', 'Moulin', 'David', 'Ab-', '06 30 35 89 78', 'david.moulin@hotmail.fr', 'adresse de Monsieur Moulin', 'au pâté', 3),
('Mâle', 'Gaildry', 'Arthur', 'Ab+', '06 72 65 30 45', 'arthur.gaildry@hotmail.fr', 'adresse de Monsieur Gaildry', 'aux tournesols', 4);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
