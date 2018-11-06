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
        bat(script: 'call C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\JenkinsTestBuild\\CompileBatch.bat', returnStatus: true, returnStdout: true)
      }
    }
    stage('Run Boot Stage 1') {
      steps {
        bat(script: 'start C:\\Jenkins\\workspace\\JenkinsTestBuild_master-HSFE4JB3YDTDRHV5TTSFLB7QDJY25TPJ74C6A5YHH6YY2QGFGWPQ\\JenkinsTestBuild\\x64\\Debug\\JenkinsTestBuild.exe BootStage1', returnStatus: true)
      }
    }
    stage('TestResults') {
      steps {
        livingDocs(numbered: true, sectAnchors: true)
      }
    }
  }
}