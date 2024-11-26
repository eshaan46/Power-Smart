## Power Smart

### **Issue At Large**
- **30%** of global electricity is used by appliances [clasp.com](https://www.clasp.ngo/report/net-zero-heroes/appliances-impacts-and-benefits/?utm_source=chatgpt.com).
- Out of this, **10-15%** is wasted due to inefficient appliance operation in our homes.
- That is approximately 2000 TWh.
- This could power many homes.
- The main disadvantage is the amount of CO2 and other pollutants added to the environment, as over 70% of electricity is still produced from fossil fuels.

---

### **Issue We are Targeting**
- Over time, appliances tend to become inefficient, whether they are light bulbs or fans.
- For example, a light bulb produces 30% light and 70% heat for a certain amount of electricity. Over time, this ratio worsens, wasting a lot of electricity in the long run.
- This happens often, so helping people measure their components' efficiency or `Power Factor` would give them an idea of their environmental impact and potential cost savings. Individually, it may seem small, but collectively, it adds up.

---

### **Proposed Solution**
- The solution I propose consists of three important parts:

#### Hardware:
- The hardware is designed to be easily installed into your breaker board. Through the breaker board, it connects to each appliance, mainly lights, fans, and ACs, which are the current priorities.
- Microcontroller (ESP-32) > I2C interface > Full bridge Rectifier (Turn AC - DC) > Triac (An Electrical switch for AC) > Breaker board (appliances), I2C interface > I912n Sensor (Measures Current, Voltage, etc.)
- The microcontroller obtains data from the sensor, and using the triacs, it can control the data being driven to the sensor. This data is then sent to our app.

#### App:
- Our app is still in development. It is being built with MIT App Maker Software. The app will sync the controller with our API.

#### Machine Learning Model:
- Our machine learning model aims to achieve an MSE loss below **0.2**. Our model has achieved **0.0006**, indicating an accuracy range of **95-99%**.
- The model's testing performance is also remarkable, with an MSE loss of **0.0007** on unseen data.
- The model is trained on brands, model types, and appliance types. It can handle up to 20 brands, each with 20 models of 20 appliances, making a total of **8000** appliances in its initial stage.

### **Future Additions**
- We plan to add the following features:
  - An accompanying chatbot to understand the data, describe it to you, and suggest necessary measures.
  - Expand the number of appliances our model can handle.
  - Add a live training system to make the model more personalized.

### **Video Link**
- This video will demonstrate the AI model and show the code of the microcontroller.
- [Video]()
### **How To Run**
- to run you will ned to install the following libraries
- `scikit-learn pandas seaborn matplotlib numpy`
