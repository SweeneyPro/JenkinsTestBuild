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
        sh '''call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvarsx86_amd64.bat
cd C:\\Jenkins\\workspace\\GitTests\\JenkinsTestBuild\\JenkinsTestBuild\\
cl *.cpp *.c
'''
      }
    }
    stage('Message') {
      steps {
        echo 'Done'
      }
    }
  }
}