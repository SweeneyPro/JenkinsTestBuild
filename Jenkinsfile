pipeline {
  agent any
  stages {
    stage('Fetch Repo') {
      steps {
        git 'https://github.com/SweeneyPro/JenkinsTestBuild.git'
      }
    }
    stage('Compile') {
      steps {
        bat 'CompileBatch'
      }
    }
    stage('Message') {
      steps {
        echo 'Done'
      }
    }
  }
}