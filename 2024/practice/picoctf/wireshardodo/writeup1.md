
<!DOCTYPE html>
<html>
<head>
    <title>
     picoctf2021- Wireshark doo dooo do doo...
    </title>
</head>
<body>
    <h1>picoctf2021- Wireshark doo dooo do doo...</h1>

    <h2>Challenge Description</h2>
    <p> yAUTHOR: DYLAN

Description
Can you find the flag?
https://mercury.picoctf.net/static/d6f9aa16d2a2c51d2e431e658d87af9e/shark1.pcapng
 
</p>

    <h2>Solution Approach</h2>
    <p>Here are the steps we took to solve the challenge:</p>
    <ol>this is pcap file.
    <li>PCAP files are data files created using a program. These files contain packet data of a network and are used to analyze the network characteristics. They also contribute to controlling the network traffic and determining network status.</li>
     <li>  with wireshark you can open and analysis it and follow tcp stream like below</li>
   <li>   <img src=" https://phantom1ss.github.io/blog/2024/practice/picoctf/wireshardodo/selectfollow.png" alt="ctf quetion image" class="inline"/></li>
<li>and then go to  5th stream and file text like this cvpbPGS{c33xno00_1_f33_h_qrnqorrs} that is cipher text</li>
<li>   <img src=" https://phantom1ss.github.io/blog/2024/practice/picoctf/wireshardodo/stream5.png" alt="stream 5 content" class="inline"/></li>
<li>and with online tool decode and find it 
    </ol>
<br>
    <h2>Flag</h2>
    <p class="flag">picoCTF{p33kab00_1_s33_u_deadbeef}
</p>

    <h2>Conclusion</h2>
    <p>this is a very   easy chanllenge for work with pca and network files and forensics</p>
</body>
</html>


 
