<p align="center"><img src="./logo.png" width="200" /></p>

<p align="center">
    <picture>
      <source 
        srcset="./light-text.png"
        media="(prefers-color-scheme: dark)"
      />
      <img 
        src="./dark-text.png" 
        alt="Logo Text"
        width="800"
       />
    </picture>
  </p>
<h4 align="center">🔥The Wildfire Detection Node Network 🔥<h6>


## Project Overview

This project involves the creation of a wireless mesh network for detecting and propagating wildfire hazards using LoRaWAN technology. The network consists of multiple nodes equipped with smoke sensors spread across a forest area.

These nodes are designed to detect the presence of smoke and alert the central hub, which acts as the gateway of the network, by relaying the information through the mesh network.

The central hub, located at one end of the network, is the only node with internet access and is responsible for sending alerts to a remote monitoring system or cloud service.

## Project Goals
* _Early Detection_: Detect forest fires at an early stage to enable prompt response.
* Mesh Network Communication: Allow nodes to communicate locally and relay messages to the hub efficiently, even if some nodes are out of direct range.
* _Low Power Consumption_: Ensure the network can operate for extended periods on battery power, given the remote location.
* _Scalability_: The network should be scalable, allowing additional nodes to be added easily.
* _Reliability_: Ensure the network is robust and capable of functioning in a forest environment where some nodes may become temporarily inaccessible.

## System Components

### Nodes :

1. `Smoke Sensor`: Each node is equipped with a smoke sensor to detect the presence of smoke.

2. `Microcontroller`: Controls the operation of the node, processes sensor data, and handles communication.

3. `LoRaWAN Module`: Enables long-range communication between nodes.

### Hub (Gateway):

1. `Microcontroller`: Similar to nodes, but with additional capabilities for internet connectivity.
2. `Internet Connectivity (GSM Module)`: Allows the hub to send alerts to a remote server or cloud service. 
3. `LoRaWAN Module`: For receiving data within the mesh network.

## Network Architecture

* _Mesh Network_: Nodes communicate with each other and relay data to the hub through a mesh network. This ensures that data can propagate even if some nodes are out of direct range of the hub.

* _Hub_: Acts as the gateway to the internet. Once a wildfire hazard is detected by any node, the message is propagated through the mesh network until it reaches the hub. The hub then sends the alert to a remote server or monitoring system.

## Setup and Configuration
_Hardware Setup_:

Assemble the nodes with the selected microcontroller, LoRaWAN module, and smoke sensor.
Configure the hub with internet connectivity and connect it to the mesh network.


_Software Setup_:

Install the necessary libraries for LoRaWAN communication and sensor integration.
Write firmware for the nodes to handle sensor data, communication, and mesh networking.
Implement firmware for the hub to manage internet communication and data relay.

_Network Configuration_:

Set up the LoRaWAN network with appropriate frequencies and power settings.
Configure the mesh network routing protocols to ensure efficient communication.