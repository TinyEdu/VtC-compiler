  jenkins:
	image: jenkins/jenkins
	container_name: jenkins_master
	ports:
  	- "2840:8080"
  	- "2841:5040"
	volumes:
  	- /mnt/tinyedu/cicd/volumes/flyway/:/var/jenkins_home/flyway/
  	- /mnt/tinyedu/cicd/volumes/jenkins/:/var/jenkins_home/
  	- /mnt/tinyedu/cicd/volumes/latestbuild/:/mnt/latestbuild/

	networks:
  	network1:
    	ipv4_address: 172.20.0.14
	restart: always

  jenkins_slave:
	image: jenkins/ssh-agent:alpine-jdk17
	container_name: jenkins_slave1
	ports:
  	- "2811:22"
	volumes:
  	- /mnt/tinyedu/cicd/volumes/flyway/:/var/jenkins_home/flyway/
  	- /mnt/tinyedu/cicd/volumes/latestbuild/:/mnt/latestbuild/
	environment:
  	- JENKINS_AGENT_SSH_PUBKEY=$(env.jenkins)
	networks:
  	network1:
    	ipv4_address: 172.20.0.15
	restart: always