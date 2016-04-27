serverIp=172.24.1.1
serverPort=5300
gst-launch-1.0 -v tcpclientsrc host=$serverIp port=$serverPort ! gdpdepay ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink sync=false
