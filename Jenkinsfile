pipeline {
    agent any
    
    stages {
        stage('Clone Repository') {
            steps {
                git 'https://github.com/TinyEdu/VtC-compiler'
            }
        }

        stage('Build') {
            steps {
                sh './run.sh CLEAN BUILD'  // or your build command (e.g., ./gradlew build)
            }
        }
    }
}
