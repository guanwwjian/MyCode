/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50625
Source Host           : localhost:3306
Source Database       : mycrawler

Target Server Type    : MYSQL
Target Server Version : 50625
File Encoding         : 65001

Date: 2016-03-04 13:13:50
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `crawler_log`
-- ----------------------------
DROP TABLE IF EXISTS `crawler_log`;
CREATE TABLE `crawler_log` (
  `URLid` int(11) NOT NULL AUTO_INCREMENT,
  `URL` varchar(255) NOT NULL,
  `ADD_TIME` datetime NOT NULL,
  `CrawlTime` datetime DEFAULT NULL,
  `hasCrawled` int(11) DEFAULT NULL,
  `PC_NO` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`URLid`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of crawler_log
-- ----------------------------

-- ----------------------------
-- Table structure for `crawler_modes`
-- ----------------------------
DROP TABLE IF EXISTS `crawler_modes`;
CREATE TABLE `crawler_modes` (
  `mid` int(11) NOT NULL AUTO_INCREMENT,
  `type` text NOT NULL,
  `mode` text NOT NULL,
  PRIMARY KEY (`mid`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of crawler_modes
-- ----------------------------
INSERT INTO `crawler_modes` VALUES ('1', 'linktextmodes', '.*(?i)java(?-i).*');
INSERT INTO `crawler_modes` VALUES ('2', 'urlmodes', 'http://www.zybang.com/question/.*');
INSERT INTO `crawler_modes` VALUES ('3', 'linktextmodes', '下一页');

-- ----------------------------
-- Table structure for `crawler_properties`
-- ----------------------------
DROP TABLE IF EXISTS `crawler_properties`;
CREATE TABLE `crawler_properties` (
  `pname` varchar(50) NOT NULL,
  `pvalue` text NOT NULL,
  PRIMARY KEY (`pname`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of crawler_properties
-- ----------------------------
INSERT INTO `crawler_properties` VALUES ('seed', 'http://www.zybang.com/question/pcsearch#word=java');
INSERT INTO `crawler_properties` VALUES ('tablelog', 'Crawler_log');
INSERT INTO `crawler_properties` VALUES ('tablemodes', 'Crawler_modes');
