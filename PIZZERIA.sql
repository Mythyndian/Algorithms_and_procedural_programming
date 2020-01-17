-- MySQL Script generated by MySQL Workbench
-- Fri Jan 17 13:18:01 2020
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`NAZWY_PIZZY`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`NAZWY_PIZZY` (
  `idNAZWY_PIZZY` INT NOT NULL,
  `nazwa_pizzy` VARCHAR(50) NULL,
  PRIMARY KEY (`idNAZWY_PIZZY`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`PIZZA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`PIZZA` (
  `idPIZZA` INT NOT NULL,
  `standardowa` INT NOT NULL,
  `id_nazwa` INT NOT NULL,
  PRIMARY KEY (`idPIZZA`, `id_nazwa`),
  INDEX `fk_PIZZA_NAZWY_PIZZY1_idx` (`id_nazwa` ASC) VISIBLE,
  CONSTRAINT `fk_PIZZA_NAZWY_PIZZY1`
    FOREIGN KEY (`id_nazwa`)
    REFERENCES `mydb`.`NAZWY_PIZZY` (`idNAZWY_PIZZY`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`KLIENCI`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`KLIENCI` (
  `idKLIENCI` INT NOT NULL,
  `klient` VARCHAR(100) NULL,
  PRIMARY KEY (`idKLIENCI`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`KELNERZY`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`KELNERZY` (
  `idKELNERZY` INT NOT NULL,
  `imie` VARCHAR(45) NULL,
  `nazwisko` VARCHAR(45) NULL,
  `prowizja` DECIMAL NULL,
  PRIMARY KEY (`idKELNERZY`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`ROZMIARY`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`ROZMIARY` (
  `idROZMIARY` INT NOT NULL,
  `rozmiar` VARCHAR(45) NULL,
  `przelicznik` INT NULL,
  PRIMARY KEY (`idROZMIARY`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`CIASTO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`CIASTO` (
  `idCIASTO` INT NOT NULL,
  `nazwa_ciasta` VARCHAR(45) NULL,
  `dodatek_do_ceny` INT NULL,
  PRIMARY KEY (`idCIASTO`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`ZAMOWIENIA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`ZAMOWIENIA` (
  `idZAMOWIENIA` INT NOT NULL,
  `data_zamowienia` TIMESTAMP NULL DEFAULT 'CURRENT_TIMESTAMP',
  `nr_stolika` INT NULL,
  `cena` DECIMAL NULL,
  `id_pizza` INT NOT NULL,
  `id_klienta` INT NOT NULL,
  `id_kelnera` INT NOT NULL,
  `id_rozmiaru` INT NOT NULL,
  `id_ciasta` INT NOT NULL,
  PRIMARY KEY (`idZAMOWIENIA`, `id_pizza`, `id_klienta`, `id_kelnera`, `id_rozmiaru`, `id_ciasta`),
  INDEX `fk_ZAMOWIENIA_PIZZA_idx` (`id_pizza` ASC) VISIBLE,
  INDEX `fk_ZAMOWIENIA_KLIENCI1_idx` (`id_klienta` ASC) VISIBLE,
  INDEX `fk_ZAMOWIENIA_KELNERZY1_idx` (`id_kelnera` ASC) VISIBLE,
  INDEX `fk_ZAMOWIENIA_ROZMIARY1_idx` (`id_rozmiaru` ASC) VISIBLE,
  INDEX `fk_ZAMOWIENIA_CIASTO1_idx` (`id_ciasta` ASC) VISIBLE,
  CONSTRAINT `fk_ZAMOWIENIA_PIZZA`
    FOREIGN KEY (`id_pizza`)
    REFERENCES `mydb`.`PIZZA` (`idPIZZA`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ZAMOWIENIA_KLIENCI1`
    FOREIGN KEY (`id_klienta`)
    REFERENCES `mydb`.`KLIENCI` (`idKLIENCI`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ZAMOWIENIA_KELNERZY1`
    FOREIGN KEY (`id_kelnera`)
    REFERENCES `mydb`.`KELNERZY` (`idKELNERZY`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ZAMOWIENIA_ROZMIARY1`
    FOREIGN KEY (`id_rozmiaru`)
    REFERENCES `mydb`.`ROZMIARY` (`idROZMIARY`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_ZAMOWIENIA_CIASTO1`
    FOREIGN KEY (`id_ciasta`)
    REFERENCES `mydb`.`CIASTO` (`idCIASTO`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`DODATKI`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`DODATKI` (
  `idDODATKI` INT NOT NULL,
  `nazwa` VARCHAR(100) NULL,
  `cena_podstawowa` DECIMAL NULL,
  PRIMARY KEY (`idDODATKI`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`DODATKI_POMOC`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`DODATKI_POMOC` (
  `idDODATKI_POMOC` INT NOT NULL,
  `id_pizzy` INT NOT NULL,
  `id_dodatku` INT NOT NULL,
  PRIMARY KEY (`idDODATKI_POMOC`, `id_pizzy`, `id_dodatku`),
  INDEX `fk_DODATKI_POMOC_PIZZA1_idx` (`id_pizzy` ASC) VISIBLE,
  INDEX `fk_DODATKI_POMOC_DODATKI1_idx` (`id_dodatku` ASC) VISIBLE,
  CONSTRAINT `fk_DODATKI_POMOC_PIZZA1`
    FOREIGN KEY (`id_pizzy`)
    REFERENCES `mydb`.`PIZZA` (`idPIZZA`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_DODATKI_POMOC_DODATKI1`
    FOREIGN KEY (`id_dodatku`)
    REFERENCES `mydb`.`DODATKI` (`idDODATKI`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`DODATKI_POMOC_BACKUP`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`DODATKI_POMOC_BACKUP` (
  `idDODATKI_POMOC_BACKUP` INT NOT NULL,
  `id_dodatku` INT NOT NULL,
  `id_pizzy` INT NOT NULL,
  PRIMARY KEY (`idDODATKI_POMOC_BACKUP`, `id_dodatku`, `id_pizzy`),
  INDEX `fk_DODATKI_POMOC_BACKUP_DODATKI1_idx` (`id_dodatku` ASC, `id_pizzy` ASC) VISIBLE,
  CONSTRAINT `fk_DODATKI_POMOC_BACKUP_DODATKI1`
    FOREIGN KEY (`id_dodatku`)
    REFERENCES `mydb`.`DODATKI` (`idDODATKI`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`PIZZA_BACKUP`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`PIZZA_BACKUP` (
  `idPIZZA_BACKUP` INT NOT NULL,
  `czy_standardowa` TINYINT NULL,
  `id_nazwa` INT NOT NULL,
  PRIMARY KEY (`idPIZZA_BACKUP`, `id_nazwa`),
  INDEX `fk_PIZZA_BACKUP_NAZWY_PIZZY1_idx` (`id_nazwa` ASC) VISIBLE,
  CONSTRAINT `fk_PIZZA_BACKUP_NAZWY_PIZZY1`
    FOREIGN KEY (`id_nazwa`)
    REFERENCES `mydb`.`NAZWY_PIZZY` (`idNAZWY_PIZZY`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;