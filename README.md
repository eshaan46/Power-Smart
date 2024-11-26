# Power Smart Project

**An AI-driven solution to optimize electrical efficiency in residential and commercial buildings.**

---

## Table of Contents

- [Introduction](#introduction)
- [Problem Statement](#problem-statement)
- [Solution Overview](#solution-overview)
- [Hardware Components](#hardware-components)
- [Software Components](#software-components)
- [System Architecture](#system-architecture)
- [Machine Learning Model](#machine-learning-model)
- [Features and Benefits](#features-and-benefits)
- [Installation and Setup](#installation-and-setup)
- [Usage Instructions](#usage-instructions)
- [Statistics and Impact](#statistics-and-impact)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

**Power Smart** is an innovative project that leverages artificial intelligence to assess and optimize the electrical efficiency of buildings. By integrating hardware components with AI models, the system provides real-time insights into power consumption, helping users make informed decisions to reduce energy waste and improve efficiency.

---

## Problem Statement

With the increasing demand for energy and the rising costs associated with it, there is a critical need to optimize electrical consumption in buildings. Traditional methods of assessing electrical efficiency are often reactive, costly, and time-consuming. There is a lack of accessible solutions that provide real-time data and actionable insights to everyday users.

**Key Challenges:**

- Inefficient energy usage leading to higher utility bills.
- Difficulty in identifying power-hungry appliances.
- Lack of real-time monitoring and predictive analytics.
- Environmental impact due to excessive energy consumption.

---

## Solution Overview

**Power Smart** addresses these challenges by providing a comprehensive system that:

- Monitors electrical parameters in real-time using sensors connected via an ESP32 microcontroller.
- Controls appliances through triacs interfaced with an I2C expansion board.
- Utilizes an AI model to analyze data and predict efficiency levels.
- Offers a user-friendly interface through an MIT App Inventor application for control and monitoring.

---

## Hardware Components

1. **ESP32 Microcontroller**
2. **I2C Expansion Board**
3. **Triacs (20 Units)**
4. **Sensors**
   - Voltage Sensors
   - Current Sensors
   - Temperature Sensors
5. **Full Bridge Rectifier**
6. **Appliances**

---

## Software Components

1. **ESP32 Firmware (Arduino C++)**
2. **AI Model (Python)**
3. **Mobile Application (MIT App Inventor)**
4. **Backend Server (Optional)**

---

## System Architecture

![System Architecture Diagram](images/system_architecture.png)

1. **User Interaction**
2. **ESP32 Microcontroller**
3. **I2C Communication**
4. **Sensor Data Processing**
5. **AI Model Analysis**
6. **User Feedback**

---

## Machine Learning Model

### **Dataset Preparation**

- **Data Collection**
  - 100 appliance models across categories: Light Bulbs, ACs, Fans, Heaters.
  - 10,000 samples generated.
- **Features**
  - Appliance Type, Model, Brand, Power (W), Voltage (V), Current (A), Operational Hours, Power Factor.
- **Target Variable**
  - Efficiency Score (Scale of 1 to 5)

### **Model Selection**

- **Random Forest Regressor**
- **Linear Regression**

### **Training and Evaluation**

- **Data Preprocessing**
  - Encoding and normalization.
- **Model Performance**
  - Random Forest outperformed Linear Regression.

---

## Features and Benefits

1. **Real-time Monitoring**
2. **Remote Control**
3. **AI-Powered Insights**
4. **Customizable Settings**
5. **Energy Savings**
6. **Environmental Impact**
7. **currently can handle up two 20 different brands and models**

---

## Installation and Setup

### **Hardware Setup**

1. Assemble the components.
2. Ensure safety during connections.

### **Software Setup**

1. ESP32 Firmware: Install libraries and upload code.
2. AI Model: Train or deploy the provided model.
3. Mobile App: Customize and install.

---

## Usage Instructions

1. **Connecting to Wi-Fi**
2. **Controlling Appliances**
3. **Receiving Data**
4. **Interpreting Results**
5. **Calibration**

---

## Statistics and Impact

- Save up to **15%** on electricity bills.
- Reduce carbon footprint.
- Increase awareness of energy usage.

---

## Future Enhancements

- Integration with Renewable Energy.
- Advanced Analytics Dashboard.
- Improved Machine Learning Models.
- Voice Control and Automation.
- Scalability for Industrial Use.
- APP development
- API development fro the model

---

**Contact Information:**

- **Email:** erobotics46@outlook.com
- **GitHub:** [yourusername](https://github.com/@eshaan46)
- if you want to run the following programs you will need to install `Arduino IDE` and download the following libraries
-  `sci-kit learn , pandas , numpy , matplotlib , seaborn , joblib` 
