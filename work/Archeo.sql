-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Client :  localhost
-- Généré le :  Jeu 12 Octobre 2017 à 14:09
-- Version du serveur :  10.1.25-MariaDB-
-- Version de PHP :  7.0.22-0ubuntu0.17.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `Archeo`
--

-- --------------------------------------------------------

--
-- Structure de la table `departements`
--

CREATE TABLE `departements` (
  `idDepartement` int(11) NOT NULL,
  `nomDepartement` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `lienPeriodesSite`
--

CREATE TABLE `lienPeriodesSite` (
  `idSite` int(11) NOT NULL,
  `idPeriode` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `lienThemesSite`
--

CREATE TABLE `lienThemesSite` (
  `idSite` int(11) NOT NULL,
  `idTheme` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `periodes`
--

CREATE TABLE `periodes` (
  `idPeriode` int(11) NOT NULL,
  `nomPeriode` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `sites`
--

CREATE TABLE `sites` (
  `idSite` int(11) NOT NULL,
  `nomSite` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL,
  `coordonnees` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `idVille` int(11) NOT NULL,
  `idTypeIntervention` int(11) NOT NULL,
  `dateDebut` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `dateFin` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `themes`
--

CREATE TABLE `themes` (
  `idTheme` int(11) NOT NULL,
  `nomTheme` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `typesIntervention`
--

CREATE TABLE `typesIntervention` (
  `idTypeIntervention` int(11) NOT NULL,
  `typeIntervention` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'fouille'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `villes`
--

CREATE TABLE `villes` (
  `idVille` int(11) NOT NULL,
  `nomCommune` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL,
  `idDepartement` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Index pour les tables exportées
--

--
-- Index pour la table `departements`
--
ALTER TABLE `departements`
  ADD PRIMARY KEY (`idDepartement`);

--
-- Index pour la table `lienPeriodesSite`
--
ALTER TABLE `lienPeriodesSite`
  ADD KEY `idSite` (`idSite`),
  ADD KEY `idPeriode` (`idPeriode`);

--
-- Index pour la table `lienThemesSite`
--
ALTER TABLE `lienThemesSite`
  ADD KEY `idSite` (`idSite`),
  ADD KEY `idTheme` (`idTheme`);

--
-- Index pour la table `periodes`
--
ALTER TABLE `periodes`
  ADD PRIMARY KEY (`idPeriode`);

--
-- Index pour la table `sites`
--
ALTER TABLE `sites`
  ADD PRIMARY KEY (`idSite`),
  ADD KEY `idVille` (`idVille`),
  ADD KEY `sites_ibfk_1` (`idTypeIntervention`);

--
-- Index pour la table `themes`
--
ALTER TABLE `themes`
  ADD PRIMARY KEY (`idTheme`);

--
-- Index pour la table `typesIntervention`
--
ALTER TABLE `typesIntervention`
  ADD PRIMARY KEY (`idTypeIntervention`);

--
-- Index pour la table `villes`
--
ALTER TABLE `villes`
  ADD PRIMARY KEY (`idVille`),
  ADD KEY `idDepartement` (`idDepartement`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `departements`
--
ALTER TABLE `departements`
  MODIFY `idDepartement` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `periodes`
--
ALTER TABLE `periodes`
  MODIFY `idPeriode` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `sites`
--
ALTER TABLE `sites`
  MODIFY `idSite` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `themes`
--
ALTER TABLE `themes`
  MODIFY `idTheme` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `typesIntervention`
--
ALTER TABLE `typesIntervention`
  MODIFY `idTypeIntervention` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT pour la table `villes`
--
ALTER TABLE `villes`
  MODIFY `idVille` int(11) NOT NULL AUTO_INCREMENT;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `lienPeriodesSite`
--
ALTER TABLE `lienPeriodesSite`
  ADD CONSTRAINT `lienPeriodesSite_ibfk_1` FOREIGN KEY (`idSite`) REFERENCES `sites` (`idSite`),
  ADD CONSTRAINT `lienPeriodesSite_ibfk_2` FOREIGN KEY (`idPeriode`) REFERENCES `periodes` (`idPeriode`);

--
-- Contraintes pour la table `lienThemesSite`
--
ALTER TABLE `lienThemesSite`
  ADD CONSTRAINT `lienThemesSite_ibfk_1` FOREIGN KEY (`idSite`) REFERENCES `sites` (`idSite`),
  ADD CONSTRAINT `lienThemesSite_ibfk_2` FOREIGN KEY (`idTheme`) REFERENCES `themes` (`idTheme`);

--
-- Contraintes pour la table `sites`
--
ALTER TABLE `sites`
  ADD CONSTRAINT `sites_ibfk_1` FOREIGN KEY (`idTypeIntervention`) REFERENCES `typesIntervention` (`idTypeIntervention`),
  ADD CONSTRAINT `sites_ibfk_2` FOREIGN KEY (`idVille`) REFERENCES `villes` (`idVille`);

--
-- Contraintes pour la table `villes`
--
ALTER TABLE `villes`
  ADD CONSTRAINT `villes_ibfk_1` FOREIGN KEY (`idDepartement`) REFERENCES `departements` (`idDepartement`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
